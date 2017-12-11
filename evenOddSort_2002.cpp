#include<iostream>
#include "knuth_shuffle.cpp"
using namespace std;
void EvenOddSort(int A[]){
    //不使用额外空间，时间复杂度O(n)，完成对数组内奇数和偶数的排序，将所有偶数排在奇数前面
    int n=A[0];    //n用于在排序后恢复A[0]保存的元素个数
    int i=1,j=n;
    A[0]=A[i];
    while(i<j) {
        while(A[j]%2 == 1 && i<j)
            j--;
        A[i] = A[j];
        while(A[i]%2 == 0 && i<j)
            i++;
        A[j] = A[i];
    }
    A[i]=A[0];
    A[0]=n;
}
int main() {
    int A[11]={10,1,2,3,4,5,6,7,8,9,10};//A[0]保存元素个数
    knuth_shuffle(A);
    EvenOddSort(A);
    for(int i=1; i <= A[0]; i++){
        cout<<"index:"<<i+1<<"  "<<"value:"<<A[i]<<endl;
    }
}
