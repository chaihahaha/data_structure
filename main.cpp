#include "LinkList.cpp"
void DelX(LinkList &L,ElemType x) {
        //删除有头表的相同元素
        LinkList p;
        if(!L->next) return;
        if(L->next->data==x) {
                p=L->next;//暂存待删除节点指针
                L->next = L->next->next;//头后面的节点前移,删除节点
                free(p);
                DelX(L,x);//继续删除头后面的相同元素
        }
        else DelX(L->next,x);//头后元素不同,换头
}
void DelX_NoHead(LinkList &L,ElemType x) {
        //删除无头表的相同元素
        LinkList p;
        if(!L) return;
        if(L->data==x) {
                p=L;
                L = L->next;
                free(p);
                DelX_NoHead(L,x);
        }
        else DelX_NoHead(L->next,x);
}
void rawPrint(LinkList &L) {
        if(L->next) {
                rawPrint(L->next);//如果有后节点先输出后面的
        }
        cout<<L->data;//输出
}
void R_print(LinkList &L) {
        //反向输出,有头链表
        rawPrint(L->next);//避开头节点
}
void DelMin(LinkList &L) {
        //带头链表删除最小节点
        LNode * curNodePtr = L, * minNodePtr = L->next, *minPrePtr = L;
        while(curNodePtr->next) {
                if(curNodePtr->next->data < minNodePtr->data) {
                        minNodePtr = curNodePtr->next;
                        minPrePtr = curNodePtr;//最小节点指针和最小节点前指针更新
                }
                curNodePtr = curNodePtr->next;//当前指针后移
        }
        minPrePtr->next = minNodePtr->next;//利用最小节点前指针删除最小节点
        free(minNodePtr);
}
LNode *DelMin_Ret(LinkList &L) {
        //带头链表删除最小节点并返回最小节点地址
        LNode * curNodePtr = L, * minNodePtr = L->next, *minPrePtr = L;
        while(curNodePtr->next) {
                if(curNodePtr->next->data < minNodePtr->data) {
                        minNodePtr = curNodePtr->next;
                        minPrePtr = curNodePtr;//最小节点指针和最小节点前指针更新
                }
                curNodePtr = curNodePtr->next;//当前指针后移
        }
        minPrePtr->next = minNodePtr->next;//利用最小节点前指针删除最小节点
        minNodePtr->next = NULL;
        return minNodePtr;
}

void sort(LinkList &L) {
        LNode *q = L;//q指针的链表使用旧头,新表
        LNode *p = new LNode(-1);//p指针的链表使用新头,旧表
        p->next = L->next;
        while(p->next) {
                q->next = DelMin_Ret(p);//q破坏旧链表,p起到暂存旧链表作用
                q = q->next;
        }
}
void Reverse(LinkList &L) {
        //带头单链表就地逆置
        LinkList curNode = L->next;//当前链表节点为头的下一个
        LinkList tmp;
        L = NULL;//去掉旧表头节点,地址作为新链表的头地址
        while(curNode) {
                tmp = curNode->next; //暂存旧表当前节点的下一个
                curNode->next = L; //将旧表当前节点放到新表头节点的前面
                L = curNode; //将头节点地址更新
                curNode = tmp;//旧表的当前节点后移
        }
}
int main() {
        LinkList p = new LNode(7);
        int array[] = {6,8,5,6,2,3,4,2};
        p->arrayAdd(array);
        p->print();

        /*cout<<endl;
        DelX_NoHead(p,2);
        p->print();*/
        
        //R_print(p);
        
        cout<<"=============="<<endl;

        /*DelMin(p);
        p->print();*/

        /*Reverse(p);
          p->print();*/

        sort(p);
          p->print();
}
