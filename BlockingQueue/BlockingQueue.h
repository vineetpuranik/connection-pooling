# include "QueueNode.h"

struct BlockingQueue {
    int size; // The current size of the queue
    int maxSize; // The maximum number of elements that the queue can house.
    QueueNode* head; // The pointer to the head of the queue.
    QueueNode* tail; // the pointer to the tail of the queue.


void* popleft(); // We will pop the head QueueNode and return the connection property
void* append(void* connection); // We will take the used connection and add it back to the end of the queue.

};