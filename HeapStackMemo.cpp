#include<iostream>
using namespace std;
struct myclass{
    int data;
};
void myfunc(myclass *add) {
    add = add +1;
    add->data = 1;
    cout<<"address is changed to:"<<add<<endl;
}
int main() {
    myclass a;
    myclass *b = new myclass();
    cout <<"Stack bottom memo a address:"<< &a<<endl;
    cout <<"Heap bottom pointer b:"<< b<<endl;
    for(a.data=0;a.data<3;a.data++) {
        myclass a;
        cout<<"Stack top memo a address:"<<&a<<endl;
        myclass *b = new myclass();
        cout<<"Heap top poiter b:"<<b<<endl;
    }
    for(a.data=0;a.data<3;a.data++) {
        myclass a;
        cout<<"Stack top memo a address:"<<&a<<endl;
        cout<<"assign stack memo &a to b"<<endl;
        myclass *b = &a;
        cout<<"stack pointer b:"<<b<<endl;
    }
    cout<<"Stack bottom memo a address:" << &a<<endl;
    cout <<"Heap bottom pointer b:"<< b<<endl;
    myfunc(&a);
    myclass *tmp = &a+1;
    //*ptr 指向内存中的内容,但是无法区分内容,无类型!
    cout<<"a address outside:" << &a<<"data outside:"<<tmp->data<<endl;
    myfunc(b);
    tmp = b+1;
    cout <<"b pointer outside::"<< b<<"data outside:"<<tmp->data<<endl;
}
