#include <iostream>
#include <stdint.h>
#include <cassert>

struct PageNode {
    PageList* owner;
    PageNode* prev;
    PageNode* next;
};

class PageList {
    PageNode* root;
public:
    PageList() = default;

    inline bool empty()
    {
        return this->root == nullptr;
    }

    void push(PageNode* p) noexcept
    {
        assert(p->prev == nullptr && p->next == nullptr && p->owner == nullptr);
       
        p->owner = this;

        p->next = this->root;
        p->prev = nullptr;

        if(this->root != nullptr) {
            this->root->prev = p;
        }

        this->root = p;
    }

    inline PageNode* pop()
    {
        assert(!this->empty());
        
        PageNode* p = this->root;
        this->root = this->root->next;
        if(this->root != nullptr) {
            this->root->prev = nullptr;
        }

        p->prev = p->next = nullptr;
        return p;
    }

    void remove(PageNode* p) 
    {
        if(p == this->root) {
            this->root = this->root->next;
        }
        else {
            PageNode* prev = p->prev;
            PageNode* next = p->next;

            if(prev != nullptr) {
                prev->next = next;
            }
            if(next != nullptr) {
                next->prev = prev;
            }
        }

        p->prev = p->next = nullptr;
    }

    inline PageNode* begin() noexcept 
    {
        return this->root;
    }

    inline bool hasNext(PageNode* cur) noexcept
    {
        return cur->next != nullptr;
    }

    inline PageNode* next(PageNode* cur) noexcept
    {
        return cur->next;
    }
};

int main() {


    return 0;
}