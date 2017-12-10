#include<iostream>
using namespace std;
void EvenOddSort(int A[]){
    int i=1,j=A[0];
    while(i<j) {
        A[0]=A[i];
        while(A[j]%2 == 1 && i<j) j--;
        if(i<j) { A[i] = A[j]; i++; }
        while(A[i]%2 == 0 && i<j) i++;
        if(i<j) { A[j] = A[i]; j--; }
        A[i]=A[0];
    }
}
int main() {
    int A[11]={10,6,3,9,2,7,5,8,4,1,10};
    EvenOddSort(A);
    for(int i=0; i < 10; i++){
        cout<<"index:"<<i+1<<"  "<<"value:"<<A[i]<<endl;
    }
}
