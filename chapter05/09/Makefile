EXE_DIR := ./bin
SRC_DIR := ./src
INC_DIR := ./inc

CC := g++
CFLAGS := -g -Wall -I$(INC_DIR) -std=c++11

TARGET := $(EXE_DIR)/main
OBJS := $(wildcard $(SRC_DIR)/*.cc)


$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	rm -rf $(TARGET)
