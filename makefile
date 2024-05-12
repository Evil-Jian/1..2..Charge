CC = gcc
CFLAGS = -Wall
BUILD_DIR = dist

all: $(BUILD_DIR) server client

$(BUILD_DIR):
	mkdir -p $@

server: ./src/charge.c src/server.c src/connection.c 
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/server

client: ./src/charge.c src/client.c src/connection.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/client
	
clean: 
	rm -rf $(BUILD_DIR)