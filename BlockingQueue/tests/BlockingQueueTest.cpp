#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <cstdint>
#include "../BlockingQueue.h"   // include your queue

void producer(BlockingQueue& queue, int id, int startValue, int count) {
    for (int i = 0; i < count; i++) {
        int value = startValue + i;
        if (queue.append((void*)(intptr_t)value) == nullptr) {
            std::cout << "[Producer " << id << "] Queue full, failed to insert " << value << std::endl;
        } else {
            std::cout << "[Producer " << id << "] Inserted " << value << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
    }
}

void consumer(BlockingQueue& queue, int id, int pops) {
    for (int i = 0; i < pops; i++) {
        void* conn = queue.popleft();  // blocks if empty
        int value = (int)(intptr_t)conn;
        std::cout << "    [Consumer " << id << "] Popped " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // simulate processing
    }
}

int main() {
    BlockingQueue queue(5);  // small capacity to trigger contention

    std::cout << "=== Multithreaded BlockingQueue Test ===" << std::endl;

    std::vector<std::thread> threads;

    // Launch 5 producers (total 25 items)
    for (int i = 0; i < 5; i++) {
        threads.emplace_back(producer, std::ref(queue), i, i * 100, 5);
    }

    // Launch 10 consumers, but each does only 2-3 pops so total = 25
    int popsPerConsumer[10] = {3,3,3,3,3,2,2,2,2,2};  

    for (int i = 0; i < 10; i++) {
    threads.emplace_back(consumer, std::ref(queue), i, popsPerConsumer[i]);
    }


    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "=== Test Complete ===" << std::endl;
    return 0;
}