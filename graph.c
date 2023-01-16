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
//        int node, end, weight;
//        pnode endNode;
//        // curr = *head;
//        getchar();
//        while (scanf("%c", &c) && c == 'n') {
//            // printf("%c\n" , c);
//            scanf("%d", &node);
//            //printf("%d\n" , node);
//            curr = getNode(*head, node);
//            while (scanf("%d", &end)) {
//                //  printf("%d\n" , end);
//                if (scanf("%d", &weight) != EOF) {
//                    //    printf("%d\n" , weight);
//                    endNode = getNode(*head, end);
//                    insertEdge(curr, endNode, weight);
//
//                }
//            }
//
//        }
//    }
//    return c;
    }
}

void printGraph_cmd(pnode head){
    if(head != NULL) {
        pnode curr = head;
        // printf("%d\n" , curr->node_num);
        while (curr != NULL) {
            // printf("%d\n" , curr->node_num);
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
}

void deleteGraph_cmd(pnode *head){
    pnode curr = *head;
    if(curr->next){
        deleteGraph_cmd(&(curr->next));
    }
   //printf("%d\n" , curr->node_num);
    delete_edges(curr->edges);
   // printf("%d\n" , curr->node_num);
    free(curr);
   // printf("%d\n" , curr->node_num);

}

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





