CFLAGS = -g -Wall

all: graph

graph: main.o edges.o algo.o nodes.o graph.o
	gcc $(CFLAGS) main.o edges.o algo.o nodes.o graph.o -o graph

main.o: main.c
	gcc $(CFLAGS) -o main.o -c main.c
edges.o: edges.c edges.h
	gcc $(CFLAGS) -o edges.o -c edges.c
algo.o: algo.c algo.h
	gcc $(CFLAGS) -o algo.o -c algo.c
nodes.o: nodes.c nodes.h
	gcc $(CFLAGS) -o nodes.o -c nodes.c
graph.o: graph.c graph.h
	gcc $(CFLAGS) -o graph.o -c graph.c

.PHONY: all clear

clean:
	rm -f *.o graph