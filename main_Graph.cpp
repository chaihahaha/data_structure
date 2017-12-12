#include "MGraph.cpp"
#include "ALGraph.cpp"
void MGraph2ALGraph(MGraph* g1,ALGraph* g2){
    for(int i = 0; i < g1->vexnum; i++){
        VNode* p = new VNode();
        p->data=g1->vexs[i];
        p->firstarc=NULL;
        g2->vertices[i]=p;
    }
    for(int i = 0; i< g1->vexnum; i++) {
        for(int j = 0; j < g1->vexnum; j++) {
            if(g1->arcs[i][j].adj==1) {
                ArcNode* arc = new ArcNode();
                arc->adjvex=j;
                arc->nextarc = g2->vertices[i]->firstarc;
                arc->info=NULL;
                g2->vertices[i]->firstarc=arc;
            }
        }
    }
}
int main(){
    MGraph* g=new MGraph(4,4);
    for(int i = 0; i < g->vexnum; i++) {
        g->vexs[i] = i;
        for(int j = 0; j < g->vexnum; j++) {
            g->arcs[i][j].adj = 1;
        }
    }
    int arcs[4][4]={{0,1,0,0},{0,0,1,1},{0,1,0,1},{1,0,1,0}};
    int vexs[4]={0,1,2,3};
    g->InitMGraph(vexs,arcs);
    for(int i = 0; i < g->vexnum; i++) {
        for(int j = 0; j < g->vexnum; j++) {
            cout<<g->arcs[i][j].adj<<"  ";
        }
        cout<<endl;
    }
    ALGraph * g_al= new ALGraph(4,4);
    MGraph2ALGraph(g,g_al);
    return 0;
}
