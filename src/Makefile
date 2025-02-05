CXX = g++
CXXFLAGS =  -std=c++23 -Wall -Wextra -Werror -Wpedantic \
-Wshadow -Wnon-virtual-dtor -Wold-style-cast \
-Wcast-align -Wunused -Woverloaded-virtual \
-Wconversion -Wsign-conversion -Wnull-dereference \
-Wdouble-promotion -Wformat=2 -Wmisleading-indentation \
-Wduplicated-cond -Wduplicated-branches -Wlogical-op \
-Wuseless-cast

TARGET = docserver

SOURCES = funciones.cc main.cc SafeFD.cc Safemap.cc

OBJECTS = $(SOURCES:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

cleano:
	rm -f $(OBJECTS)

.PHONY: all clean cleano