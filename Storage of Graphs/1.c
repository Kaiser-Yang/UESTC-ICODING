#include "graph.h" 
#include <stdio.h>

bool matrix_insert_vertex(MatrixGraph* G, VertexType v){
    if (matrix_locate_vertex(G, v) != -1) return false;
    if (G->vexnum == MAX_VERTEX_NUM) return false;
    G->vertex[G->vexnum] = v;
    for (int i = 0;i < MAX_VERTEX_NUM;i ++)
        G->arcs[G->vexnum][i] = G->arcs[i][G->vexnum] = 0;
    G->vexnum ++;
    return true;
}
bool matrix_insert_arc(MatrixGraph* G, VertexType v, VertexType w){
    int U = matrix_locate_vertex(G, v), V = matrix_locate_vertex(G, w);
    if (U == -1 || V == -1) return false;
    if (G->type == 0){
        if (G->arcs[U][V]) return false;
        G->arcs[U][V] = 1;
        G->arcnum ++;
        return true;
    }
    else{
        if (G->arcs[U][V]) return false;
        G->arcs[U][V] = G->arcs[V][U] = 1;
        G->arcnum ++;
        return true;
    }
}

