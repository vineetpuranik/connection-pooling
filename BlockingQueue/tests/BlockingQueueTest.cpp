#include <iostream>
#include <cstdint>
#include "../BlockingQueue.h"   // include your queue

int main() {
    // Create a blocking queue with capacity 3
    BlockingQueue queue;
    queue.size = 0;
    queue.maxSize = 3;
    queue.head = nullptr;
    queue.tail = nullptr;

    std::cout << "=== Testing BlockingQueue ===" << std::endl;

    // Append a few "connections" (using integers casted to void* for now)
    queue.append((void*)1);
    queue.append((void*)2);
    queue.append((void*)3);

    std::cout << "Queue size after 3 appends: " << queue.size << std::endl;

    // Try appending beyond maxSize
    auto node = queue.append((void*)4);
    if (node == nullptr) {
        std::cout << "Append rejected at max capacity (good)" << std::endl;
    }

    // Pop elements one by one
    void* conn1 = queue.popleft();
    std::cout << "Popped: " << (int)(intptr_t)conn1 << " | size: " << queue.size << std::endl;

    void* conn2 = queue.popleft();
    std::cout << "Popped: " << (int)(intptr_t)conn2 << " | size: " << queue.size << std::endl;

    void* conn3 = queue.popleft();
    std::cout << "Popped: " << (int)(intptr_t)conn3 << " | size: " << queue.size << std::endl;

    // Pop from empty queue
    void* conn4 = queue.popleft();
    if (conn4 == nullptr) {
        std::cout << "Correctly returned nullptr on empty queue" << std::endl;
    }

    return 0;
}