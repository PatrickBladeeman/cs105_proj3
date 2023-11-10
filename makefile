CXX = g++
CXXFLAGS = -std=c++11 -Wall

# List your source files
SOURCES = DarkZone.cpp Queue.cpp Stack.cpp

# Derive the object file names from source files
OBJECTS = $(SOURCES:.cpp=.o)

# The main target
DarkZone: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up intermediate files and the executable
clean:
	rm -f $(OBJECTS) DarkZone
