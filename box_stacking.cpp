#include <bits/stdc++.h>
using namespace std;

struct Box {
    int l, w, h;
};

int maxStackHeight(vector<Box>& boxes) {
    vector<Box> all;

    // Generate rotations
    for (auto b : boxes) {
        all.push_back({max(b.l, b.w), min(b.l, b.w), b.h});
        all.push_back({max(b.w, b.h), min(b.w, b.h), b.l});
        all.push_back({max(b.l, b.h), min(b.l, b.h), b.w});
    }

    // Sort by base area (descending)
    sort(all.begin(), all.end(), [](Box& a, Box& b) {
        return (a.l * a.w) > (b.l * b.w);
    });

    int n = all.size();
    vector<int> dp(n);

    // Initialize dp
    for (int i = 0; i < n; i++)
        dp[i] = all[i].h;

    // LIS style DP
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (all[j].l > all[i].l &&
                all[j].w > all[i].w) {
                dp[i] = max(dp[i], dp[j] + all[i].h);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Box> boxes = {
        {4, 6, 7},
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Maximum stack height = "
         << maxStackHeight(boxes) << endl;

    return 0;
}
