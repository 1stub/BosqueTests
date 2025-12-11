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
    bool merging;
    bool shouldstop;

    DecsProcessor(): cv(), mtx(), worker(&DecsProcessor::processDecs, this), worklist(), canrun(false), merging(false), shouldstop(false) {}

    void requestMergeAndPause(std::unique_lock<std::mutex>& lk)
    {
        this->canrun = false;
        this->merging = true;
        this->cv.notify_one();

        // Once canrun is false we know the decs thread ackd our merge
        cv.wait(lk, [this]{ 
            std::cout << "paused: " << this->canrun << std::endl;
            return !this->canrun; 
        });
    }

    void resumeAfterMerge(std::unique_lock<std::mutex>& lk)
    {
        this->canrun = true;
        this->merging = false;
        lk.unlock();
        this->cv.notify_one();
    }

    void processDecs()
    {
        while(true) {
            std::unique_lock lk(this->mtx);
            cv.wait(lk, [this]{ 
                return this->shouldstop || (this->canrun && !this->merging); 
            });

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
    decs.requestMergeAndPause(lk);
    mergeRemainingWork();
    decs.resumeAfterMerge(lk);
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