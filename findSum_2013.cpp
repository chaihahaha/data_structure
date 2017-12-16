#include<iostream>
using namespace std;
void Findsum(int A[],int x) {
    //A[0]存放元素个数，A内元素升序排列，如果在A中存在多对数字A[i]和A[j]满足A[i]+A[j]==x，输出其中任意一对
    int low = 1, high = A[0];
    while(low<high) {
        if(A[low]+A[high]==x) {
            cout<<A[low]<<"+"<<A[high]<<"="<<x<<endl;
            high--;low++;
        }
        if(A[low]+A[high]>x) high--;
        if(A[low]+A[high]<x) low++;
    }
}
int main() {
    int A[10] = {9, 1 , 1, 3,4,5,5,6,9,10};
    Findsum(A,10);
}
