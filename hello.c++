#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0/1 Knapsack Problem - Find maximum value with target weight capacity
// Time Complexity: O(n * capacity)
// Space Complexity: O(n * capacity)
class Knapsack {
public:
    // Knapsack with weights and values
    int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                // Don't include the current item
                dp[i][w] = dp[i-1][w];
                
                // Include the current item if it fits
                if (weights[i-1] <= w) {
                    dp[i][w] = max(dp[i][w], 
                                   dp[i-1][w - weights[i-1]] + values[i-1]);
                }
            }
        }
        
        return dp[n][capacity];
    }
    
    // Target Sum Problem - Can we achieve exactly targetSum using array elements?
    // Each element can be used once
    bool canAchieveTargetSum(vector<int>& arr, int targetSum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));
        
        // Base case: sum of 0 is always achievable (select nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= targetSum; sum++) {
                // Don't include current element
                dp[i][sum] = dp[i-1][sum];
                
                // Include current element if it fits
                if (arr[i-1] <= sum) {
                    dp[i][sum] = dp[i][sum] || dp[i-1][sum - arr[i-1]];
                }
            }
        }
        
        return dp[n][targetSum];
    }
    
    // Count number of ways to achieve target sum
    long long countWaysTargetSum(vector<int>& arr, int targetSum) {
        int n = arr.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(targetSum + 1, 0));
        
        // Base case: one way to make sum 0 (select nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int sum = 0; sum <= targetSum; sum++) {
                // Don't include current element
                dp[i][sum] = dp[i-1][sum];
                
                // Include current element if it fits
                if (arr[i-1] <= sum) {
                    dp[i][sum] += dp[i-1][sum - arr[i-1]];
                }
            }
        }
        
        return dp[n][targetSum];
    }
};

// Driver code
int main() {
    Knapsack ks;
    
    cout << "===== KNAPSACK PROBLEM =====" << endl;
    
    // Example 1: 0/1 Knapsack
    cout << "\n1. 0/1 Knapsack Problem:" << endl;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 8;
    
    cout << "Weights: ";
    for (int w : weights) cout << w << " ";
    cout << "\nValues: ";
    for (int v : values) cout << v << " ";
    cout << "\nCapacity: " << capacity << endl;
    cout << "Maximum value: " << ks.knapsack(weights, values, capacity) << endl;
    
    // Example 2: Target Sum Problem
    cout << "\n2. Target Sum Problem (Can achieve?):" << endl;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget Sum: " << targetSum << endl;
    
    if (ks.canAchieveTargetSum(arr, targetSum)) {
        cout << "YES, target sum is achievable!" << endl;
    } else {
        cout << "NO, target sum cannot be achieved!" << endl;
    }
    
    // Example 3: Count ways to achieve target sum
    cout << "\n3. Count Ways to Achieve Target Sum:" << endl;
    vector<int> arr2 = {1, 2, 3};
    int targetSum2 = 4;
    
    cout << "Array: ";
    for (int x : arr2) cout << x << " ";
    cout << "\nTarget Sum: " << targetSum2 << endl;
    cout << "Number of ways: " << ks.countWaysTargetSum(arr2, targetSum2) << endl;
    cout << "(Possible subsets: {1,3}, {2,2} but {2,2} requires using 2 twice)" << endl;
    
    return 0;
}
