#include "BinaryTree.cpp"
int main() {
        int a[] = {1,2,3,4,5,6,7,8,9};
        int b[] = {2,3,1,5,4,7,8,6,9};
        BinaryTree t = new BTNode(a,b);
        t->PrePrint();
        t->InPrint();
        t->Output();
        cout<<"Nodes"<<t->DsonNodes()<<endl;
}
