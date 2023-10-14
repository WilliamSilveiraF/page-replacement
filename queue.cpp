#include "queue.h"

void Queue::enqueue(int page) {
    q.push(page);
}

int Queue::dequeue() {
    int front = q.front();
    q.pop();
    return front;
}

bool Queue::isEmpty() {
    return q.empty();
}
