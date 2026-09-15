CC = gcc
CFLAGS = -std=c99 -O2

%.out: % %.in
	./$* < ./$*.in > ./$*.out

%.diff: %.out %.correct
	diff ./$*.out ./$*.correct


