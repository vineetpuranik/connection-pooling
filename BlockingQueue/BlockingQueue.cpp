#include "BlockingQueue.h"
#include <cstdlib> // for NULL

void* BlockingQueue::popleft() {
    // if the queue is empty then return null pointer
    if (head == nullptr) {
        return nullptr;
    }

    // get the current head and grab connection to be returned
    QueueNode* temp = head;
    void* conn = temp->connection;

    // if the queue has only 1 element, then remove the element and set head and tail to None
    if (size == 1) {
        head = nullptr;
        tail = nullptr;
    }
    // if queue has more than 1 element, then remove the element at head and set head as head.next. 
    else {
        head = head->next;
    }

    //decrement the current size of the queue.
    size--;

    // Free the old node
    delete temp;

    return conn;
}
