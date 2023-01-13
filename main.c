#include <stdio.h>
#include "graph.h"
#include "edges.h"
#include "nodes.h"
#include <stdlib.h>

int main() {
    char option;

    pnode graph = (pnode)malloc(sizeof(pnode));
    scanf("%c" , &option);
    printf("%c\n" , option);

    build_graph_cmd(&graph);
  insertEdge(graph->next->next->next , (graph->next->next) , 3);
  insertEdge(graph->next , (graph->next->next) , 6);
//  delete_node_cmd(&graph);
  printGraph_cmd(&graph);
//    pnode curr = graph;
//    while (curr !=NULL){
//       printf("%d\n" , curr->node_num);
//        curr = curr->next;
//    }

//   char option;
//   GRAPH_NODE_ graph;
//   scanf("%c" , &option);
//    switch (option) {
//        case 'A':
//            build_graph_cmd(&graph);
//            break;
//        case 'B':
//            insert_node_cmd(&graph);
//            break;
//        default:
//            break;
//
//    }



    return 0;
}
