#include "physicalMemory.h"

PhysicalMemory::PhysicalMemory(size_t cap) : capacity(cap) {}

bool PhysicalMemory::contains(int page) {
    return pages.find(page) != pages.end();
}

bool PhysicalMemory::isFull() {
    return pages.size() == capacity;
}

void PhysicalMemory::addPage(int page) {
    if(pages.size() < capacity) {
        pages.insert(page);
    }
}

void PhysicalMemory::removePage(int page) {
    pages.erase(page);
}

size_t PhysicalMemory::getCapacity() {
    return capacity;
}

std::unordered_set<int> PhysicalMemory::getPages() const {
    return pages;
}
