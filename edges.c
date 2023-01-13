#include "edges.h"
#include "nodes.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


void insertEdge(pnode  node , pnode end , int weight) {
    pedge ed = (pedge)malloc(sizeof(edge));
    pedge curr = node->edges;
    if (curr == NULL) {
        ed->weight = weight;
        ed->endpoint = end;
        ed->next = NULL;
        node->edges = ed;
    }
    else {
        while (curr->next != NULL) {
            //  printf("%d\n", weight);
            curr = curr->next;
            //  printf("%d\n", weight);
        }
        ed->weight = weight;
        ed->endpoint = end;
        curr->next = ed;
    }
}


void delete_edges(pedge edge){
    if(edge->next != NULL) {
        delete_edges(edge->next);
    }
    free(edge);
}

void delete_edges_of_node(pnode  *head , int name) {
    pnode node = getNode(*head, name);
    pnode curr = *head;
    while (curr != NULL) {
        printf("%d\n", curr->node_num);
        if (curr != node) {
            pedge ed = curr->edges;
            while (ed != NULL && ed->endpoint == node) {
                curr->edges = ed->next;
                free(ed);
                ed = curr->edges;
            }
            while (ed != NULL && ed->next != NULL) {
                if (ed->next->endpoint == node) {
                    pedge toClear = ed->next;
                    ed->next = toClear->next;
                    free(toClear);
                }
                else {
                    ed = ed->next;
                }
            }
        }
        curr = curr->next;
    }

}

