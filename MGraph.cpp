#include<iostream>
using namespace std;
typedef int VRType;//顶点关系类型1/0 x/oo
typedef int InfoType;//弧相关信息类型
typedef int VertexType;//顶点类型
#define MAX_VERTEX_NUM 20
typedef enum {DG,DN,UDG,UDN} GraphKind;
class ArcCell
{
public:
    VRType adj;
    InfoType * info;
};
typedef ArcCell AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
class MGraph
{
public:
    MGraph(int vexnum,int arcnum){
        this->vexnum=vexnum;
        this->arcnum=arcnum;
    }
    void InitMGraph(VertexType vexs[],int arcs[4][4]) {
        for(int i = 0; i < this->vexnum; i++) {
            this->vexs[i]=vexs[i];
        }
        for(int i = 0; i < this->vexnum; i++) {
            for(int j = 0; j < this->vexnum; j++) {
                this->arcs[i][j].adj=arcs[i][j];
            }
        }
    }
    void InitMGraph(int arcs[4][4]) {
        for(int i = 0; i < this->vexnum; i++) {
            for(int j = 0; j < this->vexnum; j++) {
                this->arcs[i][j].adj=arcs[i][j];
            }
        }
    }
    GraphKind kind;
    int vexnum, arcnum;
    AdjMatrix arcs;
    VertexType  vexs[MAX_VERTEX_NUM];
};
