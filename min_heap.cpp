// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int heap[10];
int idx =1;
int cnt=0;
void swim(){
    int k=idx-1;
    while(k >1 && heap[k/2] > heap[k]){
        int temp=heap[k/2];
        heap[k/2]=heap[k];
        heap[k]=temp;
        k=k/2;
    }
}
void addheap(int val){
    heap[idx]=val;
    cnt++;
    idx++;
    swim();
}
int extractmin(){
    int value=heap[1];
    int temp=heap[1];
    heap[1]=heap[idx-1];
    heap[idx-1]=temp;
    cnt--;
    idx--;
    sink();
}


int main() {
    int nums={4,3,1,5,0};
    for(int i=0;i<5;i++){
        addheap(nums[i]);
    }
    for(int i=0;i<5;i++){
        cout<<heap[i]<<" ";
    }
   

    return 0;
}