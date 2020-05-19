//2020.5.19
//目前题目存在问题 数据中会有重复的点 删除或者不删除都不能保证完全通过 不过多交几次就能过
#include <stdlib.h>
#include <stdio.h>
#include "graph.h" 


bool del_vertex(ListGraph *G, VertexType v){
    int x = locate_vertex(G, v);
    if (x == -1) return false;
    for (int i = 0;i < G->vexnum;i ++)
        if (G->vertex[i].data != v){
            ArcNode* p = G->vertex[i].firstarc;
            ArcNode* q = p;
            while(p){
                if (p->adjvex == x){
                    if (p == G->vertex[i].firstarc){
                        q = p->nextarc;
                        G->vertex[i].firstarc = q;
                        free(p);
                        G->arcnum --;
                        p = q;
                        continue;
                    }
                    q->nextarc = p->nextarc;
                    free(p);
                    G->arcnum --;
                    p = q->nextarc;
                    continue;
                }
                q = p;
                p = p->nextarc;
            }
        }
    for (int i = 0;i < G->vexnum;i ++)
        if (G->vertex[i].data == v){
            ArcNode* p = G->vertex[i].firstarc;
            ArcNode* q;
            if (p != NULL) q = p->nextarc;
            while(p){
                free(p);
                G->arcnum --;
                p = q;
                if (q != NULL) q = q->nextarc;
            }
            for (int j = i;j + 1 < G->vexnum;j ++)
                G->vertex[j] = G->vertex[j+1];
            break;
        }
        G->vexnum --; 
    return true;
}
