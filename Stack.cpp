#include<iostream>
#include "BinaryTree.cpp"
using namespace std;
typedef BinaryTree StackNodeElemType;
class StackNode
{
public:
    StackNodeElemType data;
    StackNode * next;
};
class Stack
{
public:
    void InitStack() {
        this->top = NULL;
    }
    void Push(StackNodeElemType x) {
        StackNode * p = new StackNode();
        p->data = x;
        p->next = top;
        top = p;
    }
    StackNodeElemType Pop() {
        StackNodeElemType ret = top->data;
        top = top->next;
        return ret;
    }
    bool IsEmpty() {
        return !top;
    }
    StackNodeElemType GetTop() {
        return top->data;
    }
    StackNode * top;
};
