#ifndef PAGEREPLACEMENTALGORITHM_H
#define PAGEREPLACEMENTALGORITHM_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include "physicalMemory.h"
#include "queue.h"

class PageReplacementAlgorithm {
protected:
    PhysicalMemory physicalMemory;

public:
    PageReplacementAlgorithm(size_t cap);
    virtual int getPageFaults(int pages[], int totalPages) = 0;
};

class FIFO : public PageReplacementAlgorithm {
private:
    Queue pagesQueue;

public:
    FIFO(size_t cap);
    int getPageFaults(int pages[], int totalPages) override;
};

class OPT : public PageReplacementAlgorithm {
public:
    OPT(size_t cap);
    int getPageFaults(int pages[], int totalPages) override;

private:
    int predict(int pages[], int totalPages, int currentIndex);
};

class LRU : public PageReplacementAlgorithm {    
private:
    std::unordered_map<int, int> timestamps;
    int time;

public:
    LRU(int cap);
    int getPageFaults(int pages[], int totalPages) override;
};

#endif
