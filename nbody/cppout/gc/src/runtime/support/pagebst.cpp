#include "../common.h"
#include "pagebst.h"

#define IS_LOW_UTIL(U) (U >= 0.01f && U <= 0.60f)
#define IS_HIGH_UTIL(U) (U > 0.60f && U <= 0.90f)


bool insertPageInBucket(GCAllocator* alloc, PageInfo* p) 
{
    float util = p->approx_utilization;
    bool islow = IS_LOW_UTIL(util);
    bool ishigh = IS_HIGH_UTIL(util);

    assert(!(islow && ishigh));

    if(islow) {
        alloc->inuse.push_front(p);
        return true;
    }
    if(ishigh) {
        alloc->inuse.push_back(p);
        return true;
    }

    return false;
}

PageInfo* getLowestUtilPageLow(GCAllocator* alloc) noexcept 
{
    if(alloc->inuse.size() == 0) {
        return nullptr;
    }

    PageInfo* p = alloc->inuse.front();
    alloc->inuse.pop_front();

    return p;
}

PageInfo* getLowestUtilPageHigh(GCAllocator* alloc) noexcept 
{
    if(alloc->inuse.size() == 0) {
        return nullptr;
    }

    PageInfo* p = alloc->inuse.back();
    alloc->inuse.pop_back();

    return p;
}