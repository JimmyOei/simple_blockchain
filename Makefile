INC_DIR = include
SRC_DIR = src
SOURCES =  $(SRC_DIR)/*.cc
OBJECTS = $(subst .cc,.o,$(SOURCES))
TARGET = simple_blockchain
CXX = g++
CFLAGS = -fPIC -Wall -Wextra
CPPFLAGS = -I$(INC_DIR)

all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)
