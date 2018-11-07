EXE_DIR := ./bin
INC_DIR := ./inc
SRC_DIR := ./src

TARGET := $(EXE_DIR)/main
OBJS := $(wildcard ./src/*.cpp)
CFLAGS := -Wall -g -I$(INC_DIR) -std=c++11

CC := g++

$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -rf $(TARGET)
