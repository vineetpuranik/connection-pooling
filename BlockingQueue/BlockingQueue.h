# include "QueueNode.h"
# include <mutex>
# include <condition_variable>

struct BlockingQueue {
    // properties
    int size; // The current size of the queue
    int maxSize; // The maximum number of elements that the queue can house.
    QueueNode* head; // The pointer to the head of the queue.
    QueueNode* tail; // the pointer to the tail of the queue.

    // Synchronization
    std::mutex mtx;
    std::condition_variable cv;

    // Constructor
    BlockingQueue(int maxSize) : size(0), maxSize(maxSize), head(nullptr), tail(nullptr) {};

    // Methods
    void* popleft(); // We will pop the head QueueNode and return the connection property
    QueueNode* append(void* connection); // We will take the used connection and add it back to the end of the queue.

};