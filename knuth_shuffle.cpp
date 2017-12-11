#include<iostream>
#include<time.h>
using namespace std;
typedef int ElemType;
void knuth_shuffle(ElemType A[]) {
    srand((unsigned)time(NULL));
    for(int i = A[0]; i > 0; i--) {
        int index=rand()%A[0]+1;
        ElemType temp;
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}
