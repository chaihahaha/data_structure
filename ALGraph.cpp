#include<iostream>
using namespace std;
typedef int InfoType;//弧相关信息类型
typedef int VertexType;//顶点类型
#define MAX_VERTEX_NUM 20
class ArcNode{
public:
    int adjvex;
    ArcNode *nextarc;
    InfoType *info;
};
class VNode{
public:
    VertexType data;
    ArcNode *firstarc;
};
typedef VNode* AdjList[MAX_VERTEX_NUM];
class ALGraph{
public:
    ALGraph(int vexnum,int arcnum){
        this->vexnum=vexnum;
        this->arcnum=arcnum;
    }
    AdjList vertices;
    int vexnum,arcnum;
};
