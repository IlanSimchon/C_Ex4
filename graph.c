#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edges.h"
#include "nodes.h"


void build_graph_cmd(pnode *head) {
    if (*head) {
        deleteGraph_cmd(head);
    }
    pnode graph = (pnode) malloc(sizeof(node));
    *(head) = graph;
    int numOfNodes;
    pnode curr = graph;
    scanf("%d", &numOfNodes);

    if (numOfNodes > 0) {
        curr->node_num = 0;
        int i = 1;
        while (i < numOfNodes) {
            graph = (pnode) malloc(sizeof(node));
            graph->node_num = i;
            graph->next = NULL;
            curr->next = graph;
            curr = graph;
            i++;
        }
    }
}

void printGraph_cmd(pnode head){
    if(head != NULL) {
        pnode curr = head;
        while (curr != NULL) {
            printf("node %d:  ", curr->node_num);
            pedge ed = curr->edges;
            while (ed != NULL) {
                printf("%d--%d-->%d ,",
                       curr->node_num, ed->weight, ed->endpoint->node_num);
                ed = ed->next;
            }
            printf("\n");
            curr = curr->next;
        }
    }
    else{
        printf("The graph is NULL\n");
    }
}

void deleteGraph_cmd(pnode *head){
    pnode curr = *head;
    if(curr->next){
        deleteGraph_cmd(&(curr->next));
    }
    delete_edges(curr->edges);
    free(*head);
    *head = NULL;
}