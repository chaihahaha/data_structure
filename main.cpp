#include "LinkList.cpp"
void DelX(LinkList &L,ElemType x) {
    //删除有头表的相同元素
    LinkList p;
    if(!L->next) return;
    if(L->next->data==x) {
        p=L->next;//暂存待删除结点指针
        L->next = L->next->next;//头后面的结点前移,删除结点
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
        L = L->next;//此语句会使引用的实参值改变,即表头被删
        free(p);
        DelX_NoHead(L,x);
    }
    else DelX_NoHead(L->next,x);
}
void rawPrint(LinkList &L) {
    if(L->next) {
        rawPrint(L->next);//如果有后结点先输出后面的
    }
    cout<<L->data;//输出
}
void R_print(LinkList &L) {
    //反向输出,有头链表
    rawPrint(L->next);//避开头结点
}
void DelMin(LinkList &L) {
    //带头链表删除最小结点
    LNode * curNodePtr = L, * minNodePtr = L->next, *minPrePtr = L;
    while(curNodePtr->next) {
        if(curNodePtr->next->data < minNodePtr->data) {
            minNodePtr = curNodePtr->next;
            minPrePtr = curNodePtr;//最小结点指针和最小结点前指针更新
        }
        curNodePtr = curNodePtr->next;//当前指针后移
    }
    minPrePtr->next = minNodePtr->next;//利用最小结点前指针删除最小结点
    free(minNodePtr);
}
LNode *DelMin_Ret(LinkList &L) {
    //带头链表删除最小结点并返回最小结点地址
    LNode * curNodePtr = L, * minNodePtr = L->next, *minPrePtr = L;
    while(curNodePtr->next) {
        if(curNodePtr->next->data < minNodePtr->data) {
            minNodePtr = curNodePtr->next;
            minPrePtr = curNodePtr;//最小结点指针和最小结点前指针更新
        }
        curNodePtr = curNodePtr->next;//当前指针后移
    }
    minPrePtr->next = minNodePtr->next;//利用最小结点前指针删除最小结点
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
    LinkList curNode = L->next;//当前链表结点为头的下一个
    LinkList tmp;
    L = NULL;//去掉旧表头结点,地址作为新链表的头地址
    while(curNode) {
        tmp = curNode->next; //暂存旧表当前结点的下一个
        curNode->next = L; //将旧表当前结点放到新表头结点的前面
        L = curNode; //将头结点地址更新
        curNode = tmp;//旧表的当前结点后移
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

    /*sort(p);
      p->print();*/
}
