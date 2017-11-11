#include<iostream>
#include "BinaryTree.cpp"
//二叉树以二叉链表为存储结构，分别写出在二叉树中查找值为X的结点算法Search和求X所在树中层数的算法Level
using namespace std;
typedef struct{
    BinaryTree data;
    int tag;
}Stack;
typedef int ElemType;
BinaryTree output;        //递归查找输出
void Search(BinaryTree t, ElemType X) {
    if(t) {
        if(t->data == X) output = t;
        if(t->left) Search(t->left,X);
        if(t->right) Search(t->right,X);
    }
}
int Level(BinaryTree t, ElemType X) { 
    Stack stack[100];
    int top = 0;
    BinaryTree p = t;
    while(p || top > 0) {
        if(p) {
            stack[++top].data = p;
            stack[top].tag = 0;
            p = p->left;
        }
        else {
            p = stack[top].data;
            if(p->right && stack[top].tag != 1) {
                stack[top].tag = 1;
                p = p->right;
            }
            else {
                if(p->data == X) {
                    break;
                }
                else {
                    top--;
                    p = NULL;
                }
            }
        }
    }
    return top;
}
int main() {
    int a[] = {1,2,3,4,5,6,7,8,9};
    int b[] = {2,3,1,5,4,7,8,6,9};
    BinaryTree t = new BTNode(a,b);
    t->Output();
    cout<<endl;
    cout<<Level(t,8)<<endl;
    Search(t,8);
    cout<<output->data<<endl;
}
