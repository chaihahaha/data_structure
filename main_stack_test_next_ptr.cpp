#include "Stack_test_next_ptr.cpp"
int main() {
    Stack s;
    s.InitStack();
    s.Push(2);s.Push(3);
    cout<<endl;
    cout<<"nextptr outside "<<s.top->next<<endl;
    cout<<endl;
    cout<<"pop value: "<<s.Pop()<<endl;
    cout<<endl;
    cout<<"gettop: "<<s.GetTop()<<endl;
    cout<<endl;
    cout<<"pop value: "<<s.Pop()<<endl;
    cout<<endl;
    cout<<"isemp value: "<<s.IsEmpty()<<endl;
    StackNode p;
    p.data =1;
    StackNode *q=&p;
    q=q+1;
    
    typedef struct vnode{
        int data;
    }vnode, adj[2];
    adj r;
    r[0].data=1;
    cout<<r[0].data;
    
    *q = p; //不能用*直接对指针所指对象赋值？可以
    //*q = 1; 不同类型不能赋值
    //cout<<(*q)<<endl;这个自定义类型不能直接输出
}
