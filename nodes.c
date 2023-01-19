#include "graph.h"
#include "edges.h"
#include <stdio.h>
#include <stdlib.h>

int getCount(pnode head){
    pnode curr = head;
    int count = 0;
    while (curr){
        count++;
        curr = curr->next;
    }
    return count;
}

pnode getNode(pnode head , int a){
    pnode curr = head;
    while (curr != NULL){
        if(curr->node_num == a)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void insert_node_cmd(pnode *head){
    int name;
    scanf("%d" , &name);
    pnode curr = getNode(*head , name);
    if(curr != NULL){
            delete_edges(curr->edges);
            curr->edges = NULL;
       }
    else {
        curr = *head;
        pnode new = (pnode) malloc(sizeof (node));
        new->node_num = name;
        new->next = NULL;
        new->edges = NULL;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new;
        curr = curr->next;
    }
    int end , weight;
    while (scanf("%d" , &end) && scanf("%d" , &weight)){
        insertEdge(curr , getNode(*head ,end) , weight);
    }
}

void delete_node_cmd(pnode *head) {
    int name;
    scanf("%d", &name);
    delete_edges_of_node(head , name);
    pnode first = *head;
    if (first->node_num == name) {
        delete_edges(first->edges);
        *head = first->next;
        free(first);
    }
    else {
        pnode node = getNode(*head, name);
        delete_edges(node->edges);

        pnode curr = *head;
        while (curr->next != node) {
            curr = curr->next;
        }
        curr->next = node->next;
        free(node);
    }
}