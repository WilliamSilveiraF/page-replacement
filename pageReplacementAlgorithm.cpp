#include "pageReplacementAlgorithm.h"

PageReplacementAlgorithm::PageReplacementAlgorithm(size_t cap) : physicalMemory(cap) {}

FIFO::FIFO(size_t cap) : PageReplacementAlgorithm(cap) {}

int FIFO::getPageFaults(int pages[], int n) {
    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if (!physicalMemory.contains(pages[i])) {
            if (physicalMemory.isFull()) {
                int oldestPage = pagesQueue.dequeue();
                physicalMemory.removePage(oldestPage);
            }
            physicalMemory.addPage(pages[i]);
            pagesQueue.enqueue(pages[i]);
            page_faults++;
        }
    }
    return page_faults;
}

OPT::OPT(size_t cap) : PageReplacementAlgorithm(cap) {}

int OPT::predict(int pg[], std::vector<int>& fr, int pn, int index) {
    int res = -1, farthest = index;
    for (size_t i = 0; i < fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}

int OPT::getPageFaults(int pages[], int n) {
    std::vector<int> fr;
    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if(find(fr.begin(), fr.end(), pages[i]) != fr.end()) {
            continue;
        }
        if (fr.size() < physicalMemory.getCapacity()) {
            fr.push_back(pages[i]);
        } else {
            int j = predict(pages, fr, n, i + 1);
            fr[j] = pages[i];
        }
        page_faults++;
    }
    return page_faults;
}

LRU::LRU(int cap) : PageReplacementAlgorithm(cap), time(0) {}

int LRU::getPageFaults(int pages[], int n) {
    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        time++;
        if (!physicalMemory.contains(pages[i])) {
            if (physicalMemory.isFull()) {
                int lru_page = INT_MAX, oldest_time = INT_MAX;
                for (const auto& pair : timestamps) {
                    if (pair.second < oldest_time) {
                        oldest_time = pair.second;
                        lru_page = pair.first;
                    }
                }
                physicalMemory.removePage(lru_page);
                timestamps.erase(lru_page);
            }
            physicalMemory.addPage(pages[i]);
            page_faults++;
        }
        timestamps[pages[i]] = time; 
    }
    return page_faults;
}
