#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int left, int mid , int right) {
        int i = left, j = mid + 1, k = 0;
        vector<int> temp(right - left + 1);
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        for (i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
        }
    }
    void mergeSort(vector<int>& arr , int left ,int right){
        if(left==high){
            return;
        }
        int mid =(left+right)/2;
        mergeSort(arr, left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
        
    }


};
int main() {
    vector<int> arr = {5, 2, 8, 4, 1};
    Solution sol;
    sol.mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}