#include "graph.h"
#include "limits.h"
#include "nodes.h"
#include <stdio.h>
#include "algo.h"
#include "stdlib.h"
//void deleteGraph_cmd(pnode* head){
//    int start , end;
//    scanf("%d" , &start);
//    scanf("%d" , &end);
//    int numOfNoeds = getCount(*head);
//    pnode st = getNode(*head , start);
//    pnode en = getNode(*head , end);
//
//
//}
void printQ(ppq head){
ppq curr = head;
    while (curr){
        printf("%d  -  %d  " , curr->node->node_num , curr->dist_now);
        curr=curr->next;
    }
    printf("\n");
}


void push(ppq *head , pnode new){
    ppq curr = *head;
    ppq newNode = (ppq) malloc(sizeof (pq));
    newNode->dist_now = new->dist;
    newNode->node = new;
    if(curr == NULL || curr->dist_now >= new->dist){
        newNode->next = curr;
        *head = newNode;
    }
    else {
        while (curr->next && new->dist > curr->dist_now && new->dist > curr->next->dist_now){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
  //  printQ(*head);
}


ppq pop(ppq *head){
    ppq temp = *head;
    *head = temp->next;
    return temp;
}


int shortsPath_cmd(pnode head){
    int start , end;
    scanf("%d" , &start);
    scanf("%d" , &end);
    ppq priority = NULL;
    pnode curr = head;
    while (curr){
        curr->dist = INT_MAX;
        curr->visited = 0;
        if(curr->node_num == start){
            curr->dist = 0;
            push(&priority , curr);
        }
        // next
        curr = curr->next;
    }
    while (priority != NULL){
        ppq temp = pop(&priority);
        pedge ed = temp->node->edges;
        while (ed != NULL){
            if(ed->endpoint->visited == 0) {
                int length = temp->dist_now + ed->weight;
                if (length < ed->endpoint->dist) {
                    ed->endpoint->dist = length;
                    push(&priority , ed->endpoint);
                }
            }
            ed = ed->next;
        }
        temp->node->visited = 1;
        free(temp);
    }
    pnode this = getNode(head , end);
    if(this->dist == INT_MAX){
        return -1;
    }
    return this->dist;
}

