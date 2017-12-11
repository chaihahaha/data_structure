#include<iostream>
using namespace std;
typedef int VRType;//顶点关系类型1/0 x/oo
typedef int InfoType;//弧相关信息类型
typedef int VertexType;//顶点类型
typedef enum {DG,DN,UDG,UDN} GraphKind;
class ArcCell
{
public:
    VRType adj;
    InfoType * info;
};
class MGraph
{
public:
    void InitMGraph(int vexnum,int arcnum){
        this->vexnum=vexnum;
        this->arcnum=arcnum;
        VertexType vexs[vexnum];
        ArcCell arcs[vexnum][vexnum];
        this->vexs=vexs;
        this->arcs=arcs;
    }
    GraphKind kind;
    int vexnum, arcnum;
    ArcCell arcs[][];
    VertexType  vexs[];
};
