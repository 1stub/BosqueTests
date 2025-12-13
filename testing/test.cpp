#include <iostream>
#include <stdint.h>
#include <cassert>

#include <cstdlib>
#include <chrono>

#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>

#define NUM_COLLECTIONS 1'000

size_t g_thd_cntr;

struct DecsProcessor {
    std::mutex mtx;
    std::condition_variable cv;
    std::unique_ptr<std::thread> thd;    

    std::list<int> work;

    enum class State {
        Running,
        Pausing,
        Paused,
        Stopping,
        Stopped
    };
    State st;

    // We should start paused and ensure no thread has been created yet
    DecsProcessor(): mtx(), cv(), thd(nullptr), work(), st(State::Paused) {}

    // Delay start to ensure rest of fields are properly setup (and those of other objects)
    void init()
    {
        this->thd = std::make_unique<std::thread>([this] { this->process(); });
        g_thd_cntr++;
    }

    void changeStateFromMain(State nst, State ack)
    {
        this->st = nst;
        this->cv.notify_one();
        std::unique_lock lk(this->mtx);
        this->cv.wait(lk, [this, ack]{ return this->st == ack; });
    }

    void changeStateFromWorker(State nst, std::unique_lock<std::mutex>& lk)
    {
        this->st = nst;
        this->cv.notify_one();
    }

    void pause()
    {
        if(this->st == State::Paused) {
            return ;
        }
        
        this->changeStateFromMain(State::Pausing, State::Paused);
    }

    void resume()
    {
        this->st = State::Running;
        this->cv.notify_one();
    }

    void stop()
    {
        this->pause(); // Ensure we are waiting
        this->changeStateFromMain(State::Stopping, State::Stopped);

        this->thd->join();
        if(this->thd->joinable()) {
            std::cerr << "Thread did not finish joining!\n";
            std::abort();
        }

        g_thd_cntr--;
    }

    void process()
    {
        std::unique_lock lk(this->mtx); // Creates a lock but says nothing about ownership
        while(true) {
            this->cv.wait(lk, [this]
                { return this->st != State::Paused; }
            );

            if(this->st == State::Stopping) {
                this->changeStateFromWorker(State::Stopped, lk);
                return ;
            }

            while(!this->work.empty()) {
                if(this->st != State::Running) break;
                this->work.pop_front(); // do some work
            }
            
            this->changeStateFromWorker(State::Paused, lk);
        }
    }
};

thread_local DecsProcessor g_dp;

int main()
{
    using namespace std::chrono_literals;
    g_dp.init();

    for(int i = 0; i < NUM_COLLECTIONS; i++) {
        std::this_thread::sleep_for(10ms);

        // Lets pause for the durration of the collection
        g_dp.pause();

        // Merge in "work" that would have been from the allocator
        const int nwork = 10'000;
        for(int i = 0; i < nwork; i++)
            g_dp.work.push_back(i);

        // Process half
        for(int i = 0; i < nwork/2; i++)
            g_dp.work.pop_front();

        g_dp.resume();
    }

    g_dp.stop();

    return 0;
}