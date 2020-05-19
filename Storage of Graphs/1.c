#include "graph.h" // 请不要删除，否则检查不通过
#include <stdio.h>

bool matrix_insert_vertex(MatrixGraph* G, VertexType v)
{
    if (matrix_locate_vertex(G, v) != -1)
        return false;
    if (G->vexnum == MAX_VERTEX_NUM)
        return false;
    G->vertex[G->vexnum] = v;
    for (int i = 0; i < MAX_VERTEX_NUM; i++)
        G->arcs[G->vexnum][i] = G->arcs[i][G->vexnum] = false;
    G->vexnum++;
    return true;
}

bool matrix_insert_arc(MatrixGraph* G, VertexType v, VertexType w)
{
    int U = matrix_locate_vertex(G, v);
    int V = matrix_locate_vertex(G, w);
    if (U == -1 || V == -1)
        return false;
    if (G->type == 0) {
        if (G->arcs[U][V])
            return false;
        G->arcs[U][V] = true;
        G->arcnum++;
    } else {
        if (G->arcs[U][V] && G->arcs[V][U])
            return false;
        if (!G->arcs[U][V])
            G->arcs[U][V] = true, G->arcnum++;
        if (!G->arcs[V][U])
            G->arcs[V][U] = true, G->arcnum++;
    }
    return true;
}
