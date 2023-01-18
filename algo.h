#include "graph.h"


typedef struct PriorityQueue{
    pnode node;
    int dist_now;
    struct PriorityQueue *next;
} pq , *ppq;

void push(ppq *head , pnode new);
ppq pop(ppq *head);
int shortsPath_cmd(pnode head);
int Dijkstra(pnode head , int start , int end);
int TSP_cmd(pnode head);
int permute(int *arr, pnode head , int l, int r) ;
int comp (const void * elem1, const void * elem2);
int factorial(int n);

#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

#endif //C_EX4_ALGO_H
