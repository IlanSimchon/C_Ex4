#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edges.h"
#include "nodes.h"





void build_graph_cmd(pnode *head) {
    int numOfNodes;
    pnode curr = *head;
    char c;

    scanf("%d", &numOfNodes);

    if (numOfNodes > 0) {
        curr->node_num = 0;
        int i = 1;
        while (i < numOfNodes) {
            pnode graph = (pnode)malloc(sizeof(node));
            graph->node_num = i;
            graph->next = NULL;
            curr->next = graph;
            curr = graph;
            i++;
        }
        int node, end, weight;
        pnode endNode;
        // curr = *head;
        getchar();
        while (scanf("%c", &c) && c == 'n') {
            // printf("%c\n" , c);
            scanf("%d", &node);
            //printf("%d\n" , node);
            curr = getNode(*head, node);
            while (scanf("%d", &end)) {
                //  printf("%d\n" , end);
                if (scanf("%d", &weight) != EOF) {
                    //    printf("%d\n" , weight);
                    endNode = getNode(*head, end);
                    insertEdge(curr, endNode, weight);

                }
            }

        }
    }
}


void printGraph_cmd(pnode *head){
    pnode  curr = *head;
    // printf("%d\n" , curr->node_num);
    while (curr != NULL){
        // printf("%d\n" , curr->node_num);
        printf("node %d:  " , curr->node_num);
        pedge ed = curr->edges;
        while (ed != NULL){
            printf("%d--%d-->%d ," ,
                   curr->node_num , ed->weight , ed->endpoint->node_num);
            ed = ed->next;
        }
        printf("\n");
        curr = curr->next;
    }
}





