#include <stdio.h>
#include "graph.h"
#include "edges.h"
#include "nodes.h"
#include <stdlib.h>
#include "algo.h"

int main() {
//    char option;
//
//   pnode *graph = (pnode*)malloc(sizeof(pnode));
//    scanf("%c" , &option);
//    printf("%c\n" , option);
//
//    build_graph_cmd(graph);
//    insertEdge((*graph)->next->next->next , ((*graph)->next->next) , 3);
//    insertEdge((*graph)->next , ((*graph)->next->next) , 6);
//
//    printGraph_cmd(*graph);
//    int a = shortsPath_cmd(*graph);
//    printf("%d\n" , a);

   char option;
   int start;
    pnode source;
    pnode *graph = (pnode*)malloc(sizeof(pnode));
    while (scanf("%c" , &option) != EOF) {
        switch (option) {
            case 'A':
                build_graph_cmd(graph);
                break;
            case 'n':
                scanf("%d" , &start);
                source = getNode(*graph , start);
                nInsertEdge(*graph , source);
                break;
            case 'B':
                insert_node_cmd(graph);
                break;
            case 'D':
                delete_node_cmd(graph);
                break;
            case 'S':
                printf("%d\n" , shortsPath_cmd(*graph));
                break;
            case 'T':
              //  TSP_cmd(graph);
                break;
            default:
                break;

        }
    }
    free(graph);
    return 0;
}
