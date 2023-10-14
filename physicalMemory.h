#ifndef PHYSICALMEMORY_H
#define PHYSICALMEMORY_H

#include <unordered_set>
#include <cstddef>

class PhysicalMemory {
private:
    std::unordered_set<int> pages;
    size_t capacity;

public:
    PhysicalMemory(size_t cap);

    bool contains(int page);
    bool isFull();
    void addPage(int page);
    void removePage(int page);
    size_t getCapacity();
};

#endif
