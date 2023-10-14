#ifndef MANAGER_H
#define MANAGER_H

#include "pageReplacementAlgorithm.h"

class Manager {
private:
    FIFO fifo;
    OPT opt;
    LRU lru;

public:
    Manager(size_t cap);
    void executeFIFO(int pages[], int n);
    void executeOPT(int pages[], int n);
    void executeLRU(int pages[], int n);
};

#endif
