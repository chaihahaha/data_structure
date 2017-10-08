#include "Stack.cpp"
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
        t->PrePrint();
        t->InPrint();
        t->Output();
        PostPrint(t);
        cout<<endl;
}
