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
        
}
