#include "edges.h"
#include "nodes.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>


void insertEdge(pnode  node , pnode end , int weight) {
    pedge ed = (pedge) malloc(sizeof(edge));
    ed->next = NULL;
    ed->endpoint = NULL;
    pedge curr = node->edges;
        if (curr == NULL) {
            ed->weight = weight;
            ed->endpoint = end;
            ed->next = NULL;
            node->edges = ed;
        } else {
            while (curr->next != NULL) {
                if (curr->endpoint->node_num == end->node_num) return;
                curr = curr->next;
            }
            ed->weight = weight;
            ed->endpoint = end;
            curr->next = ed;
        }
    }



void delete_edges(pedge edge) {
    if (edge) {
        if (edge->next != NULL) {
            delete_edges(edge->next);
        }
      //  printf("now free: %d\n" , edge->weight);
        free(edge);
    }
}

    void nInsertEdge(pnode head) {
        int start;
        pnode source;
        scanf("%d" , &start);
        source = getNode(head , start);
        int end, weight;
        pnode endNode;
        while (scanf("%d", &end)) {
            if (scanf("%d", &weight) != EOF) {
                endNode = getNode(head, end);
                if(source != NULL && endNode != NULL) {
                    insertEdge(source, endNode, weight);
                }
                else{
                    printf("error in output\n");
                }

            }
        }
    }

    void delete_edges_of_node(pnode *head, int name) {
        pnode node = getNode(*head, name);
        pnode curr = *head;
        while (curr != NULL) {
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
                    } else {
                        ed = ed->next;
                    }
                }
            }
            curr = curr->next;
        }

    }

