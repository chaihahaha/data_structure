#include "Queue.cpp"
int main() {
        Queue a;
        a.InitQueue();
        a.EnQueue(2);
        a.EnQueue(3);
        cout<<a.DeQueue()<<endl;
}
