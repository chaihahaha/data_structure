#include "MGraph.cpp"
#include "ALGraph.cpp"
void MGraph2ALGraph(MGraph &g1,ALGraph &g2){
    //把邻接矩阵表示的图g1转为邻接表表示
    for(int i = 0; i < g1.vexnum; i++){
        VNode* p = new VNode();
        p->data=g1.vexs[i];
        p->firstarc=NULL;
        g2.vertices[i]=p;
    }
    for(int i = 0; i< g1.vexnum; i++) {
        for(int j = 0; j < g1.vexnum; j++) {
            if(g1.arcs[i][j].adj==1) {
                ArcNode* arc = new ArcNode();
                arc->adjvex=j;
                arc->nextarc = g2.vertices[i]->firstarc;
                arc->info=NULL;
                g2.vertices[i]->firstarc=arc;
                cout<<"Adding Arc: "<<i<<" -> "<<g2.vertices[i]->firstarc->adjvex<<endl;//删除这个语句后不能正常生成邻接表，为什么？
            }
        }
    }
}
void DFS(ALGraph &g,int vi){
    //从vi顶点开始进行深度优先遍历
    ArcNode * stack[g.arcnum];
    int top=0;
    bool visited[g.vexnum];
    for(int i=0; i < g.vexnum; i++) visited[i]=false;
    ArcNode *p=g.vertices[vi]->firstarc;
    cout<<vi<<"  ";
    visited[vi]=true;    
    while(p||top>0) {
        if(p) {
            if(!visited[p->adjvex]) {
                cout<<p->adjvex<<"  ";
                visited[p->adjvex]=true;
                stack[++top]=p;
                p=g.vertices[p->adjvex]->firstarc;
            }
            else
                p = p->nextarc;
        }
        else
            p = stack[top--]->nextarc;
    }
    cout<<endl;
}
void AllPaths(ALGraph &g,int vi,int vj){
    //从vi顶点到vj开始进行深度优先遍历，求出所有路径
    ArcNode * stack[g.arcnum];
    int top=0;
    bool visited[g.vexnum];
    for(int i=0; i < g.vexnum; i++) visited[i]=false;
    ArcNode *p=g.vertices[vi]->firstarc;
    visited[vi]=true;
    visited[vj]=true;
    while(p||top>0) {
        if(p) {
            if(p->adjvex==vj){
                int i=0;
                for(;i < top; i++) {
                    cout<<stack[i]->adjvex<<"  ";
                }
                if(i>0) cout<<vj<<endl;
                
            }
            if(!visited[p->adjvex]) {
                visited[p->adjvex]=true;
                stack[++top]=p;
                p=g.vertices[p->adjvex]->firstarc;
            }
            else
                p = p->nextarc;
        }
        else
            p = stack[top--]->nextarc;
    }
}
int main(){
    MGraph g(6,10);
    for(int i = 0; i < g.vexnum; i++) {
        g.vexs[i] = i;
        for(int j = 0; j < g.vexnum; j++) {
            g.arcs[i][j].adj = 1;
        }
    }
    int *arcs[6];
    int temp[][6]={{0,1,1,0,1,0},{1,0,1,1,1,1},{0,1,0,1,1,1},{1,1,1,0,1,0},{1,1,0,1,0,1},{0,1,1,0,1,0}};
    arcs[0]=temp[0];
    arcs[1]=temp[1];
    arcs[2]=temp[2];
    arcs[3]=temp[3];
    arcs[4]=temp[4];
    arcs[5]=temp[5];
    int vexs[6]={0,1,2,3,4,5};
    g.InitMGraph(vexs,arcs);
    for(int i = 0; i < g.vexnum; i++) {
        for(int j = 0; j < g.vexnum; j++) {
            cout<<g.arcs[i][j].adj<<"  ";
        }
        cout<<endl;
    }
    ALGraph g_al(6,10);
    MGraph2ALGraph(g,g_al);
    DFS(g_al,0);
    AllPaths(g_al,0,2);
    return 0;
}
