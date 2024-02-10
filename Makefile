CC = gcc
AR = ar
FLAGS = -Wall -g

all: my_graph my_Knapsack

my_Knapsack: my_Knapsack.o
	${CC} ${FLAGS} -o my_Knapsack my_Knapsack.o 

my_Knapsack.o: my_Knapsack.c
	${CC} ${FLAGS} -c my_Knapsack.c

my_graph: my_graph.o 
	${CC} ${FLAGS} -o my_graph my_graph.o 

	
my_graph.o: my_graph.c my_mat.h
	${CC} ${FLAGS} -c my_graph.c

my_mat.o: my_mat.h my_mat.c
	${CC} ${FLAGS} -c my_mat.c

.PHONY: clean all

clean:
	rm -f *.o *.so *.exe
