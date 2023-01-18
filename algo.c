#include "graph.h"
#include "limits.h"
#include "nodes.h"
#include "algo.h"
#include <stdio.h>
#include <stdlib.h>


// PriorityQueue

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
}

ppq pop(ppq *head){
    ppq temp = *head;
    *head = temp->next;
    return temp;
}

// algorithms

int shortsPath_cmd(pnode head){
    int start , end;
    scanf("%d" , &start);
    scanf("%d" , &end);
    return Dijkstra(head , start , end);
}

int Dijkstra(pnode head , int start , int end){
    ppq priority = NULL;
    pnode curr = head;
    while (curr){
        curr->dist = INT_MAX;
        curr->visited = 0;
        if(curr->node_num == start){
            curr->dist = 0;
            push(&priority , curr);
        }
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

int TSP_cmd(pnode head){
    int num;
    scanf("%d" , &num);
    int *go = (int*) malloc(num*sizeof(int));
    for (int i = 0; i < num; ++i) {
        scanf("%d" , &go[i]);
    }
    qsort(go , num , sizeof (int) , comp );
    int answer = permute(go, head ,0, num- 1);
    free(go);
    return answer;
}

int permute(int *arr, pnode head , int l, int r) {
    int min_way = INT_MAX;
    int i, j;
    do {
        int sum = 0;
        for (int k = l; k < r; k++) {
            int x = Dijkstra(head , arr[k] , arr[k+1]);
            if(x == -1) {
                sum = INT_MIN;
            }
            else {
                sum += x;
            }
        }
        if(min_way > sum && sum >=0)
            min_way = sum;

        // find the rightmost element that is smaller than the element next to it
        i = r - 1;
        while (i >= l && arr[i] >= arr[i+1])
            i--;
        if (i < l)
            break;

        // find the rightmost element that is greater than the element found above
        j = r;
        while (arr[j] <= arr[i])
            j--;

        // swap the elements
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        // reverse the elements to the right of the element found above
        i++;
        j = r;
        while (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i >= l);
    if(min_way == INT_MAX)
        return -1;
    return  min_way;
}


int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}


int factorial(int n){
    if(n == 1)
        return 1;
    return n * factorial(n-1);
}
