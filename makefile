CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Object files
QUEUE_OBJ = Queue.o
STACK_OBJ = Stack.o
DARKZONE_OBJ = DarkZone.o

# Target executable
TARGET = DarkZone

all: $(TARGET)

$(TARGET): $(QUEUE_OBJ) $(STACK_OBJ) $(DARKZONE_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(QUEUE_OBJ): Queue.cpp Queue.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(STACK_OBJ): Stack.cpp Stack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DARKZONE_OBJ): DarkZone.cpp Queue.h Stack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(QUEUE_OBJ) $(STACK_OBJ) $(DARKZONE_OBJ) $(TARGET)

.PHONY: all clean
