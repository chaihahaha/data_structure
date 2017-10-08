#include<iostream>
using namespace std;
typedef int ElemType;
class QueueNode
{
public:
        ElemType data;
        QueueNode * next;
};
class Queue
{
public:
        void InitQueue() {
                QueueNode * p = new QueueNode();
                this->front= p;
                this->rear=p;
                this->front->next = NULL;
        }
        bool IsEmpty() {
                if(this->front==this->rear) return true;
                else return false;
        }
        void EnQueue(ElemType x) {
                QueueNode *p = new QueueNode();//动态内存分配,堆内存
                p->data=x;
                p->next=NULL;
                this->rear->next=p;
                this->rear=p;
                
        }
        ElemType DeQueue() {
                if(this->front==this->rear) return -1;
                QueueNode * p = this->front->next;
                ElemType ret = p->data;
                this->front->next=p->next;
                if(this->rear==p) this->rear=this->front;
                delete p;
                return ret;
        }
        QueueNode *front,*rear;
};

