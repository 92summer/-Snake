
CC = gcc
object:= main.o food.o map.o rules.o snake.o

all: src Snake

Snake: ${object}
	${CC} -o $@ ${object}
	echo OK

src:
	${CC} -c main.c
	${CC} -c food.c
	${CC} -c map.c
	${CC} -c rules.c
	${CC} -c snake.c

clean: ${object}
	del -r ${object}
