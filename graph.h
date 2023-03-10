#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    // for Dijkstra
    int dist;
    int visited;
} node, *pnode;


void build_graph_cmd(pnode *head);
void printGraph_cmd(pnode head);
void deleteGraph_cmd(pnode *head);

#endif
