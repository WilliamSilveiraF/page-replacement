#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

class Memory {
private:
    unordered_set<int> pages;
    size_t capacity;

public:
    Memory(size_t cap): capacity(cap) {}

    bool contains(int page) {
        return pages.find(page) != pages.end();
    }

    bool isFull() {
        return pages.size() == capacity;
    }

    void addPage(int page) {
        if(pages.size() < capacity) {
            pages.insert(page);
        }
    }

    void removePage(int page) {
        pages.erase(page);
    }
};

class Queue {
private:
    std::queue<int> q;

public:
    void enqueue(int page) {
        q.push(page);
    }

    int dequeue() {
        int front = q.front();
        q.pop();
        return front;
    }

    bool isEmpty() {
        return q.empty();
    }
};

class Fifo {
private:
    Memory memory;
    Queue pagesQueue;

public:
    Fifo(int cap): memory(cap) {}

    int getPageFaults(int pages[], int n) {
        int page_faults = 0;
        for (int i = 0; i < n; i++) {
            if (!memory.contains(pages[i])) {
                if (memory.isFull()) {
                    int oldestPage = pagesQueue.dequeue();
                    memory.removePage(oldestPage);
                }
                memory.addPage(pages[i]);
                pagesQueue.enqueue(pages[i]);
                page_faults++;
            }
        }
        return page_faults;
    }
};

class LRU {
private:
    Memory memory;
    unordered_map<int, int> timestamps;
    int time;

public:
    LRU(int cap): memory(cap), time(0) {}

    int getPageFaults(int pages[], int n) {
        int page_faults = 0;
        for (int i = 0; i < n; i++) {
            time++;
            if (!memory.contains(pages[i])) {
                if (memory.isFull()) {
                    int lru_page = INT_MAX, oldest_time = INT_MAX;
                    for (const auto& pair : timestamps) {
                        if (pair.second < oldest_time) {
                            oldest_time = pair.second;
                            lru_page = pair.first;
                        }
                    }
                    memory.removePage(lru_page);
                    timestamps.erase(lru_page);
                }
                memory.addPage(pages[i]);
                page_faults++;
            }
            timestamps[pages[i]] = time; 
        }
        return page_faults;
    }
};


class Manager {
private:
    Fifo fifo;
    LRU lru;

public:
    Manager(int cap): fifo(cap), lru(cap) {}

    void executeFifo(int pages[], int n) {
        cout << "Page Faults using FIFO: " << fifo.getPageFaults(pages, n) << endl;
    }

    void executeLRU(int pages[], int n) {
        cout << "Page Faults using LRU: " << lru.getPageFaults(pages, n) << endl;
    }
};

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    Manager manager(4);
    manager.executeFifo(pages, sizeof(pages)/sizeof(pages[0]));
    manager.executeLRU(pages, sizeof(pages)/sizeof(pages[0]));
    return 0;
}
