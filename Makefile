CC = gcc
CFLAGS = -std=c99 -O3

2.out: 2 2.in
	./2 < 2.in > 2.out

diff: 2.out 2.correct
	diff 2.out 2.correct


