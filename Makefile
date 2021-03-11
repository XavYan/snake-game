CC=g++
CFLAGS=-g -std=c++17 -Wall -Wextra -Iinclude -Iutils

all: src/main.cc build/Cell.o build/Snake.o build/Game.o
	$(CC) $(CFLAGS) -o snakeGame src/main.cc build/Cell.o build/Snake.o build/Game.o

build/Cell.o: include/Cell.h src/Cell.cc
	$(CC) $(CFLAGS) -c -o build/Cell.o src/Cell.cc
build/Snake.o: include/Snake.h src/Snake.cc
	$(CC) $(CFLAGS) -c -o build/Snake.o src/Snake.cc
build/Game.o: include/Game.h src/Game.cc
	$(CC) $(CFLAGS) -c -o build/Game.o src/Game.cc
