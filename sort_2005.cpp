#include<iostream>
using namespace std;
typedef int datatype;
typedef struct {
	int key;
	datatype data;
	int count;
}node;
node R[4];
void Sort(node R[]) {                                                //不移动结点存储位置，在结点count字段记录结点在排序中的序号，并将排序结果升序输出 (哈工大2005)
	datatype min;                                                    //最小元素
	int minIndex;                                                    //最小元素的索引
	for(int i = 0; i < 4; i++) {
        R[i].key = i;                                                //对key赋值，将count清0
        R[i].count = 0;
    }
    for(int k = 1; k < 5; k++) {                                     //外层循环查找第k小的元素
        for(int i = 0; i < 4/*不能在这里进行条件选择*/; i++) {          //查找第1个未输出的元素作为初始最小元素
            if(R[i].count == 0) {
                min = R[i].data;
                minIndex = i;
                break;
            }
        }
        for(int i = 0; i < 4/*不能在这里进行条件选择*/ ; i++) {          //内层循环查找第k小的元素索引i
            if(R[i].data <= min && R[i].count == 0) {
                min = R[i].data;
                minIndex = i;
            }
        }
        R[minIndex].count = k;                                       //对第k小的元素结点count字段赋值
        cout<<R[minIndex].data<<endl;                                //输出第k小的元素
    }
}
int main(){
	node n[4];
	n[0].data=3;
	n[1].data=7;
	n[2].data=1;
	n[3].data=4;
	Sort(n);
	for(int i = 0; i < 4; i++) {
		cout<<"key:"<<n[i].key<<"   data:"<<(n[i].data)<<"  count:"<<(n[i].count)<<endl;
	}
	return 0;
}
