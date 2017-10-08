#include<iostream>
using namespace std;

class BTNode
{
    typedef int ElemType;
public:
    BTNode(ElemType data) {//创建有给定值的树根
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    template<class T>
    BTNode(T &A,T &B) {//用先序序列A和中序序列B创建一整个树
        BTNode * root = PreInCreateOverLoad(A,B,0,sizeof(A)/sizeof(A[0]) - 1,0,sizeof(B)/sizeof(B[0]) - 1);
        this->data = root->data;
        this->left = root->left;
        this->right = root->right;
    }
    void InPrint() {//打印中序序列
        this->InPrintOverLoad();
        cout<<endl;
    }
        
    void PrePrint() {//打印先序序列
        this->PrePrintOverLoad();
        cout<<endl;
    }
    void Output() {//打印树的图形,树根在最左侧
        BTNode* root = this;
        if (root->right)
            {
                output_impl(root->right, false, "");
            }
        cout << root->data << endl;
        if (root->left)
            {
                output_impl(root->left, true, "");
            }
    }
    int DsonNodes() {//打印双分支结点数
        BTNode * b = this;
        if(!b) return 0;
        else if(b->left && b->right) return b->left->DsonNodes()+b->right->DsonNodes()+1;
        else return b->left->DsonNodes()+b->right->DsonNodes();
    }
    ElemType data;
    BTNode * left;
    BTNode * right;
private:
    void output_impl(BTNode* n, bool left, string const& indent)
    {
        if (n->right)
            {
                output_impl(n->right, false, indent + (left ? "|     " : "      "));
            }
        cout << indent;
        cout << (left ? '\\' : '/');
        cout << "-----";
        cout << n->data << endl;
        if (n->left)
            {
                output_impl(n->left, true, indent + (left ? "      " : "|     "));
            }
    }

    void PrePrintOverLoad() {
        BTNode * p = this;
        if(p) {
            cout<<p->data<<" ";
            p->left->PrePrintOverLoad();
            p->right->PrePrintOverLoad();
        }
    }
    void InPrintOverLoad() {
        BTNode * p = this;
        if(p) {
            p->left->InPrintOverLoad();
            cout<<p->data<<" ";
            p->right->InPrintOverLoad();
        }
    }
    BTNode * PreInCreateOverLoad(ElemType A[], ElemType  B[], int l1,int r1,int l2,int r2) {
        BTNode *root = new BTNode(A[l1]);
        int i = l2;
        while(B[i] != root->data)
            i++;
        int llen = i-l2;
        int rlen = r2 - i;
        if(llen)
            root->left = PreInCreateOverLoad(A,B,l1+1,l1+llen,l2,l2+llen - 1);
        else
            root->left = NULL;
        if(rlen)
            root->right = PreInCreateOverLoad(A,B,r1-rlen+1,r1,r2-rlen+1,r2);
        else
            root->right = NULL;
        return root;
    }
};
typedef BTNode *BinaryTree;
