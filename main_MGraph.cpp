#include "MGraph.cpp"
int main(){
    MGraph g=new MGraph(4,4);
    for(int i = 0; i < g.vexnum; i++) {
        g.vexs[i] = i;
        for(int j = 0; j < g.vexnum; j++) {
            g.arcs[i][j].adj = 1;
        }
    }
    // for(int i = 0; i < g.vexnum; i++) {
    //     g.vexs[i] = i;
    //     for(int j = 0; j < g.vexnum; j++) {
    //         g.arcs[i][j].adj = 1;
    //     }
    // }
    return 0;
}
