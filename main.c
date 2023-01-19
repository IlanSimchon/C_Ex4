#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edges.h"
#include "nodes.h"
#include "algo.h"

int main() {
   char option;
 //  int start;
//    pnode source;
//    source->next = NULL;
//    source->edges = NULL;
//    source->edges = NULL;
//    source->next = NULL;
    pnode *graph = (pnode*)malloc(sizeof(pnode));
  //  *graph = NULL;
 // graph = NULL;
  *graph = NULL;
//    (**graph).edges = NULL;
//    (**graph).next = NULL;
    while (scanf("%c" , &option) != EOF) {
        switch (option) {
            case 'A':
                build_graph_cmd(graph);
                break;
            case 'n':
//                scanf("%d" , &start);
//                source = getNode(*graph , start);
                nInsertEdge(*graph);
                break;
            case 'B':
                insert_node_cmd(graph);
                break;
            case 'D':
                delete_node_cmd(graph);
                break;
            case 'S':
                printf("Dijsktra shortest path: %d \n" , shortsPath_cmd(*graph));
                break;
            case 'T':
                printf("TSP shortest path: %d \n" , TSP_cmd(*graph));
                break;
            default:
                break;

        }
    }
    deleteGraph_cmd(graph);
    free(graph);
    return 0;
}
