CC = gcc
AR = ar
FLAGS = -Wall -g

all: connections

connections: my_graph.o mat.a
	${CC} ${FLAGS} -o connections my_graph.o mat.a

mat.a: my_mat.o
	${AR} -rcs mat.a my_mat.o
	
my_graph.o: my_graph.c my_mat.h
	${CC} ${FLAGS} -c my_graph.c

my_mat.o: my_mat.h my_mat.c
	${CC} ${FLAGS} -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.so *.exe
