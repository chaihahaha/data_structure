#include<iostream>
#include "BinaryTree.cpp"
using namespace std;

class StackNode
{
        typedef BinaryTree ElemType;
public:
        ElemType data;
        StackNode * next;
};
class Stack
{
        typedef BinaryTree ElemType;
public:
        void InitStack() {
                this->top = NULL;
        }
        void Push(ElemType x) {
                StackNode * p = new StackNode();
                p->data = x;
                p->next = top;
                top = p;
        }
        ElemType Pop() {
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
