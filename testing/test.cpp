#include <iostream>
#include <stdint.h>
#include <cassert>

#include <cstdlib>

#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>

#define NUM_COLLECTIONS 50

struct DecsProcessor {
    std::condition_variable cv;
    std::mutex mtx;
    std::jthread worker;

    std::list<size_t> worklist;

    bool canrun;
    bool shouldstop;

    DecsProcessor(): cv(), mtx(), worker(&DecsProcessor::processDecs, this), worklist(), canrun(false) {}

    void processDecs()
    {
        while(true) {
            std::unique_lock lk(this->mtx);
            cv.wait(lk, [this]{ return this->canrun || this->shouldstop; });

            if(this->shouldstop) {
                break;
            }

            // Have been granted permission to do some work 
            while(!this->worklist.empty()) {
                this->worklist.pop_front();
            }
        }
    }
};
static DecsProcessor decs;
static std::list<size_t> work;

static void runAllocator(size_t allocs)
{
    for(size_t i = 0; i < allocs; i++) {
        work.push_back(i);
    }
}

static void mergeRemainingWork()
{
    for(const auto& e : work) {
        decs.worklist.push_back(e);
    }
    work.clear();
}

static void pauseDecsAndMerge()
{
    std::unique_lock lk(decs.mtx);
    decs.canrun = false;
    decs.cv.notify_one();

    //
    // We will want to use the cv to wait the decs thread
    // instead of forced sleep
    // Maybe two methods, requestMergeAndPause, and resumeAfterMerge
    // that will be called form here
    //

    // Need to make sure the decs thread is ready
    lk.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    lk.lock();

    // Decs should be waiting now
    mergeRemainingWork();

    decs.canrun = true;
    lk.unlock();
    decs.cv.notify_one();
}

static void processSomeWork()
{
    size_t halfsize = work.size() / 2;
    for(size_t i = 0; i < halfsize; i++) {
        work.pop_front();
    }  
}

static bool finishedWork()
{
    return work.empty();
}

static void collect()
{
    processSomeWork();
    
    if(!finishedWork()) {
        pauseDecsAndMerge();
    }
}

int main() 
{
    // Do nontrivial amount of work
    for(int i = 0; i < NUM_COLLECTIONS; i++) {
        size_t nallocs = rand() % 50'000;
        std::cout << "Collection " << i << "; Allocs: " << nallocs << std::endl;
        runAllocator(nallocs);
        collect();
    }

    // Just for simplicity force decs to stop
    std::unique_lock lk(decs.mtx);
    decs.shouldstop = true;
    lk.unlock();
    decs.cv.notify_one();

    return 0;
}