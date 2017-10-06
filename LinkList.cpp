#include<iostream>
using namespace std;
typedef int ElemType;
class LNode
{
public:
        LNode(ElemType data) {
                this->data = data;
                this->next = NULL;
        }
        
        void add(ElemType data) {
                LNode * p = this;
                while(p->next)
                        p=p->next;
                p->next = new LNode(data);
        }
        template<class T>
        void arrayAdd(T &a) {
                for(int i=0;i<sizeof(a)/sizeof(a[0]);i++) {
                        this->add(a[i]);
                }
        }
        void print() {
                LNode * p = this;
                int count = 0;
                while(p) {
                        cout << "LinkList["<<count<<"]:"<<p->data<<endl;
                        p=p->next;
                        count++;
                }
        }
        ElemType data;
        LNode *next;
};
typedef LNode *LinkList;

