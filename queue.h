#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* tail;

public:
    Queue() : front(nullptr), tail(nullptr) {}

    ~Queue();

    void enqueue(int page);
    int dequeue();
    bool isEmpty();
};

#endif