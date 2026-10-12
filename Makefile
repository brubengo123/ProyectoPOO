ifeq ($(OS),Windows_NT)
  ifneq ($(wildcard C:/msys64/ucrt64/bin/g++.exe),)
    CXX := C:/msys64/ucrt64/bin/g++.exe
    RM := C:/msys64/usr/bin/rm.exe -f
  else
    CXX := g++
    RM := del /Q
  endif
else
  CXX := g++
  RM := rm -f
endif

CXXFLAGS := -std=c++17 -Wall -Wextra -g
TARGET := Sistemaderefugio.exe
SOURCES := main.cpp Animal.cpp refugio.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)
