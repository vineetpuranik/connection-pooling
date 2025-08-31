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

QueueNode* BlockingQueue::append(void* connection) {
    // if connection is null pointer then return null pointer
    if (connection == nullptr) {
        return nullptr;
    }

    // if size is equal to max size then return null pointer
    if (size == maxSize) {
        return nullptr;
    }


    // create a new QueueNode
    QueueNode* node = new QueueNode;
    node->connection = connection;
    node->next = nullptr;

    // if queue size is 0 then set head and tail to be the new QueueNode
    if (size == 0) {
        head = node;
        tail = node;
    }
    
    // if queue size is > 0 then set tail.next = new QueueNode and update tail to new QueueNode
    else {
        tail->next = node;
        tail = node;
    }
    

    // increment the size
    size++;

    return node;
}