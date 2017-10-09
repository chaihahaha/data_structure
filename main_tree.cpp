#include "Stack.cpp"
typedef int ElemType;
void PostPrint(BinaryTree t) {//打印后序序列
    Stack s;
    s.InitStack();
    BinaryTree p = t;
    BinaryTree r = NULL;
    while(p||!s.IsEmpty()) {
        if(p) {
            s.Push(p);
            p = p->left;
        }
        else {
            p = s.GetTop();//如果这里前面加上BinaryTree声明语句会覆盖有效值
            if(p->right && p->right != r) {
                p=p->right;
            }
            else {                                
                cout<<s.Pop()->data<<" ";
                r=p;
                p = NULL;
            }
        }
    }
}
void PrintAncester(BinaryTree t,ElemType x ) {//打印给定结点值的所有祖先
    Stack s;
    s.InitStack();
    BinaryTree p = t;
    BinaryTree r = NULL;
    while(p||!s.IsEmpty()) {
        if(p) {
            s.Push(p);
            p = p->left;
        }
        else {
            p = s.GetTop();//如果这里前面加上BinaryTree声明语句会覆盖有效值
            if(p->right && p->right != r) {
                p=p->right;
            }
            else {
                p = s.Pop();
                if(p->data == x) break;
                r=p;
                p = NULL;
            }
        }
    }
    while(!s.IsEmpty()) {
        cout<<s.Pop()->data<<" ";
    }
}
typedef struct{
        BinaryTree tree;
        int tag;
}stack;
void PostPrint_easy(BinaryTree t) {//打印后序序列
    stack s[10];
    int top = 0;
    BinaryTree p = t;
    
    while(p||top>0) {
        if(p) {
            s[++top].tree = p;
            s[top].tag = 0;
            p = p->left;
        }
        else {
            p = s[top].tree;
            if(p->right && s[top].tag != 1) {
                s[top].tag = 1;
                p=p->right;
            }
            else {                                
                cout<<s[top--].tree->data<<" ";
                p = NULL;
            }
        }
    }
}
void LinkLeaf(BinaryTree t) {//把叶结点连在一起
    stack s[10],d[10];
    int top = 0,top1 = 0;
    BinaryTree p = t;
    
    while(p||top>0) {
        if(p) {
            s[++top].tree = p;
            s[top].tag = 0;
            p = p->left;
        }
        else {
            p = s[top].tree;
            if(p->right && s[top].tag != 1) {
                s[top].tag = 1;
                p=p->right;
            }
            else {
                if(!p->left && !p->right) d[++top1].tree = p;
                top--;
                p = NULL;
            }
        }
    }
    top = 0;
    while(top1>0) s[++top].tree = d[top1--].tree;
    p = s[top--].tree;
    while(top>0) {
        p->right = s[top--].tree;
        p = p->right;
    }
}
void Exchange(BinaryTree B) {
    if(B->left ||B->right) {
        BinaryTree tmp = B->left;
        B->left = B->right;
        B->right = tmp;
        if(B->left) Exchange(B->left);
        if(B->right) Exchange(B->right);
    }
}
int main() {
    int a[] = {1,2,3,4,5,6,7,8,9};
    int b[] = {2,3,1,5,4,7,8,6,9};
    BinaryTree t = new BTNode(a,b);
    //t->PrePrint();
    //t->InPrint();
    t->LevelPrint();
    cout<<endl;
    t->Output();
    //PostPrint(t);
    cout<<endl;
    
    //PostPrint_easy(t);
    //LinkLeaf(t);
    //BinaryTree head = t->left->right;
    //while(head) {
        //cout<<head->data<<" ";
    //  head = head->right;
    //}
    cout<<endl;
    //PrintAncester(t,7);
}
