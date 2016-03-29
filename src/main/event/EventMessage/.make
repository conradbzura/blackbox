COMPILER = clang-3.6
FLAGS = -g -std=c++11 -Wall -stdlib=libc++

.PHONY: all clean OBJECTS

all: OBJECTS
	
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

OBJECTS: $(SOURCES) $(HEADERS)
	$(COMPILER) $(FLAGS) -c $<
	 
clean:
	-rm -f *.o
