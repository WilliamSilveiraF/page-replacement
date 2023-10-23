#include "queue.h"
#include <stdexcept>

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int page) {
    Node* newNode = new Node(page);
    if (isEmpty()) {
        front = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty. Cannot dequeue.");
    }

    Node* temp = front;
    int data = temp->data;
    front = front->next;

    if (!front) {
        tail = nullptr; 
    }

    delete temp;
    return data;
}

bool Queue::isEmpty() {
    return !front;
}