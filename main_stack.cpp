#include "Stack.cpp"
int main() {
        Stack s;
        s.InitStack();
        s.Push(2);s.Push(3);
        cout<<s.Pop()<<endl;
cout<<s.GetTop()<<endl;
        cout<<s.Pop()<<endl;
        cout<<s.IsEmpty()<<endl;
        
}
