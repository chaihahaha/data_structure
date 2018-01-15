#include<iostream>
using namespace std;
void evenOddSort(int A[]) {
    int i = 1;
    int j = 2;
    while(i <= A[0] && j <= A[0]) {
        while(A[i]%2 == 1 && i <= A[0]) i+=2;
        while(A[j]%2 == 0 && j <= A[0]) j+=2;
        if(A[i]%2 == 0 && A[j]%2 ==1) {
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
}
int main() {
    int A[] = {9,2,4,1,6,3,5,9,7,8};
    evenOddSort(A);
    for(int i = 1; i <= A[0]; i++) {
        cout<<A[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
