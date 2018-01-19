#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#include<iostream>
typedef int Status;
typedef struct {
    int data;
    int info;
}ElemType;
class SqList
{
public:
    SqList(int length) {
        this->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
        if(!this->elem) exit(OVERFLOW);
        this->length = length;
        this->listsize = LIST_INIT_SIZE;
    }
    void quick_sort() {
        //以data为主关键字进行快速排序
        qsort(1, this->length);
    }
    ElemType *elem;
    int length;
    int listsize;
private:
    int partition(int low, int high) {
        this->elem[0] = this->elem[low];
        int pivotkey = this->elem[low].data;
        while(low < high) {
            while(low < high && this->elem[high].data>=pivotkey) --high;
            this->elem[low]=this->elem[high];
            while(low < high && this->elem[low].data<=pivotkey) ++low;
            this->elem[high]=this->elem[low];
        }
        this->elem[low] = this->elem[0];
        return low;
    }
    void qsort(int low, int high) {
        if(low<high) {
            int pivotloc = partition(low, high);
            qsort(low, pivotloc-1);
            qsort(pivotloc+1, high);
        }
    }
};
