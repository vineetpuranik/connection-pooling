# connection-pooling
Connection pooling using a blocking queue

## Implement FIFO queue of connections
* Implement queue.
* Each element in the queue will be a node.
* Every node will have 2 props : 1. connection : reference to connection and 2. next : reference to the next Node in the queue. 
* We will maintain head and tail of the queue so that popleft() and append() are O(1) operations.
* We will also have a maxSize property for the queue.