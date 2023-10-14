#include "manager.h"
#include <iostream>

Manager::Manager(size_t cap) : fifo(cap), opt(cap), lru(cap) {}

void Manager::executeFIFO(int pages[], int n) {
    std::cout << "FIFO: " << fifo.getPageFaults(pages, n) << " PFs" << std::endl;
}

void Manager::executeOPT(int pages[], int n) {
    std::cout << "OPT: " << opt.getPageFaults(pages, n) << " PFs" << std::endl;
}

void Manager::executeLRU(int pages[], int n) {
    std::cout << "LRU: " << lru.getPageFaults(pages, n) << " PFs" << std::endl;
}
