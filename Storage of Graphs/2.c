#include <stdlib.h>
#include <stdio.h>
#include "graph.h" 

bool insert_vertex(ListGraph *G, VertexType v){
    if (locate_vertex(G, v) != -1) return false;
    if (G->vexnum == MAX_VERTEX_NUM) return false;
    G->vertex[G->vexnum].data = v;
    G->vertex[G->vexnum].firstarc = NULL;
    G->vexnum ++;
    return true;
}
bool insert_arc(ListGraph *G, VertexType v, VertexType w){
    int U = locate_vertex(G, v), V = locate_vertex(G, w);
    if (U == -1 || V == -1) return false;
    if (G->type == 0){
        ArcNode* cur = G->vertex[U].firstarc;
        while(cur){
            if (cur->adjvex == V) return false;
            cur = cur->nextarc;
        }
        ArcNode* e = malloc(sizeof(ArcNode));
        e->adjvex = V;
        e->info = NULL;
        e->nextarc = G->vertex[U].firstarc;
        G->vertex[U].firstarc = e;
        G->arcnum ++;  
        return true;
    }
    else{
        ArcNode* cur = G->vertex[U].firstarc;
        while(cur){
            if (cur->adjvex == V) return false;
            cur = cur->nextarc;
        }
        ArcNode* e = malloc(sizeof(ArcNode));
        e->adjvex = V;
        e->info = NULL;
        e->nextarc = G->vertex[U].firstarc;
        G->vertex[U].firstarc = e;
        e = malloc(sizeof(ArcNode));
        e->adjvex = U;
        e->info = NULL;
        e->nextarc = G->vertex[V].firstarc;
        G->vertex[V].firstarc = e;
        G->arcnum ++;
        return true;
    }
}
