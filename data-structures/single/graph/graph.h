#ifndef GRAPH_H
#define GRAPH_H

typedef struct g_edge
{
        int value;
        g_node *source;
        g_node *dest;
}g_edge;

typedef struct g_node
{
        int value;
        g_edge **incident;
}g_node;

typedef g_node ** graph;

//utils
int _edge_value

        

#endif
