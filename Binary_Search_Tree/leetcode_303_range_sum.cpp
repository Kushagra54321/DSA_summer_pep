class NumArray {
    //  vector<int>prefix(nums.size(),0);
public:
vector<int>prefix;
    NumArray(vector<int>& nums) {
        // vector<int>prefix(nums.size(),0);
        int n = nums.size();
        prefix.resize(n + 1);
        prefix[0] = 0;
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
        
    }
};