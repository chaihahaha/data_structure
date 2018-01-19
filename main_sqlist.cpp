#include "SqList.cpp"
using namespace std;
int main() {
    //对线性表进行初始化和赋值
    SqList L(5);
    int ld[5] = {5, 9, 3, 8, 6 };
    int li[5] = {20,40,10,80,30};
    for(int i = 0; i < 5; i++) {
        L.elem[i+1].data = ld[i];
        L.elem[i+1].info = li[i];
    }
    

    //快速排序和输出
    L.quick_sort();
    for(int i = 0; i < 5; i++) {
        cout<<L.elem[i+1].data<<" ";
        cout<<L.elem[i+1].info<<endl;
    }
    return 0;
}
