#include "pageReplacementAlgorithm.h"

PageReplacementAlgorithm::PageReplacementAlgorithm(size_t cap) : physicalMemory(cap) {}

FIFO::FIFO(size_t cap) : PageReplacementAlgorithm(cap) {}

int FIFO::getPageFaults(int pages[], int totalPages) {
    int page_faults = 0;
    for (int i = 0; i < totalPages; i++) {
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

int OPT::predict(int pages[], int totalPages, int currentIndex) {
    int frameToReplace = -1;
    int latestUsageIndex = currentIndex;

    for (int page : physicalMemory.getPages()) {
        int j;
        for (j = currentIndex; j < totalPages; j++) {
            if (page == pages[j]) {
                if (j > latestUsageIndex) {
                    latestUsageIndex = j;
                    frameToReplace = page;
                }
                break;
            }
        }

        if (j == totalPages) return page;
    }

    return (frameToReplace == -1) ? *physicalMemory.getPages().begin() : frameToReplace;
}

int OPT::getPageFaults(int pages[], int totalPages) {
    int page_faults = 0;

    for (int i = 0; i < totalPages; i++) {
        if(physicalMemory.contains(pages[i])) {
            continue;
        }
        if (!physicalMemory.isFull()) {
            physicalMemory.addPage(pages[i]);
        } else {
            int pageToRemove = predict(pages, totalPages, i + 1);
            physicalMemory.removePage(pageToRemove);
            physicalMemory.addPage(pages[i]);
        }
        page_faults++;
    }
    return page_faults;
}

LRU::LRU(int cap) : PageReplacementAlgorithm(cap), time(0) {}

int LRU::getPageFaults(int pages[], int totalPages) {
    int page_faults = 0;
    for (int i = 0; i < totalPages; i++) {
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
