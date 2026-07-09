#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;

    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        int size = 1;
        while (size < n) size *= 2;

        tree.assign(2 * size, 0);
        buildTree(nums, 0, n - 1, 1);
    }

    void buildTree(vector<int>& nums, int start, int end, int node) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;
        buildTree(nums, start, mid, node * 2);
        buildTree(nums, mid + 1, end, node * 2 + 1);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    int query(int left, int right){
        if(left > right){
            return 0;

        }
        if(left == right){
            return tree[left];
        }
        int mid = left + (right - left) / 2;
        return query(left, mid) + query(mid + 1, right);
    }
    void update(int index, int value) {
        int n = tree.size() / 2;
        index += n;
        tree[index] = value;

        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }
    void printTree() {
        for (int i = 1; i < tree.size(); i++) {
            if (tree[i] != 0) {
                cout << tree[i] << " ";
            }
        }
        cout << "\n";
    }
};

int main() {
    vector<int> nums = {5, -1, 3, 2, -4};
    SegmentTree st(nums);
    st.printTree();
    cout << st.query(1, 3) << "\n";
    st.update(1, 10);
    st.printTree();
    return 0;
}