CC = gcc
AR = ar
FLAGS = -Wall -g

all: my_graph 


my_graph: my_graph.o my_mat.o
	$(CC) $(FLAGS) -o my_graph my_graph.o my_mat.o
	
my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c my_mat.h

my_mat.o: my_mat.h my_mat.c
	$(CC) $(FLAGS) -c my_mat.c my_mat.h

.PHONY: clean all

clean:
	rm -f *.o *.so *.exe *.a my_graph my_Knapsack my_mat.h.gch
