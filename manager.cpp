#include "manager.h"
#include <iostream>

Manager::Manager(size_t cap) : fifo(cap), opt(cap), lru(cap) {}

void Manager::executeFIFO(int pages[], int totalPages) {
    std::cout << "FIFO: " << fifo.getPageFaults(pages, totalPages) << " PFs" << std::endl;
}

void Manager::executeOPT(int pages[], int totalPages) {
    std::cout << "OPT: " << opt.getPageFaults(pages, totalPages) << " PFs" << std::endl;
}

void Manager::executeLRU(int pages[], int totalPages) {
    std::cout << "LRU: " << lru.getPageFaults(pages, totalPages) << " PFs" << std::endl;
}
