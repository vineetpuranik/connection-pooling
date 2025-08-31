CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# build test binary
test: BlockingQueue/tests/BlockingQueueTest.cpp BlockingQueue/BlockingQueue.cpp
	$(CXX) $(CXXFLAGS) $^ -o test_queue

# clean up build artifacts
clean:
	rm -f test_queue
