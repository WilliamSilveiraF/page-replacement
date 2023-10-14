#ifndef QUEUE_H
#define QUEUE_H

#include <queue>

class Queue {
private:
    std::queue<int> q;

public:
    void enqueue(int page);
    int dequeue();
    bool isEmpty();
};

#endif // QUEUE_H
