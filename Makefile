CC=clang++
CFLAGS=-pedantic-errors -gdwarf-4 -std=c++17
LDFLAGS=
SOURCES=src/main.cpp src/datetimeLIB.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=datetime

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
