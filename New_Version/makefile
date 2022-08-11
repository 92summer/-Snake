CC = gcc
o_path = ./obj

all: Snake src ${o_path}/*.o

Snake:
	${CC} -o main.o food.o map.o rules.o snake.o

src:
	${CC} -c main.c
	${CC} -c food.c
	${CC} -c map.c
	${CC} -c rules.c
	${CC} -c snake.c
