#include<iostream>
//#include "BinaryTree.cpp"
using namespace std;

class StackNode
{
    typedef int ElemType;
public:
    ElemType data;
    StackNode * next;
};
class Stack
{
    typedef int ElemType;
public:
    void InitStack() {
        this->top = NULL;
        cout<<"top in init: "<<top<<endl;
    }
    void Push(ElemType x) {
        //StackNode * p = new StackNode();
        StackNode p;
        p.data = x;
        p.next = top;//栈内存在工作栈弹出时会释放?下一次调用工作栈时使用同样的内存地址
        cout<<"nextptr in push: "<<p.next<<endl;
        top = &p;
        //p->data = x;
        //p->next = top;
        //top = p;
    }
    ElemType Pop() {
        cout<<"nextptr in pop: "<<top->next<<endl;
        ElemType ret = top->data;
        top = top->next;
        return ret;
    }
    bool IsEmpty() {
        return !top;
    }
    ElemType GetTop() {
        return top->data;
    }
    StackNode * top;
};
