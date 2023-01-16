#include "graph.h"


typedef struct PriorityQueue{
    pnode node;
    int dist_now;
    struct PriorityQueue *next;
} pq , *ppq;


void push(ppq *head , pnode new);
ppq pop(ppq *head);
int shortsPath_cmd(pnode head);

#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

#endif //C_EX4_ALGO_H
