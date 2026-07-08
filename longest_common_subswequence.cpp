#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Longest Common Subsequence Problem
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class LongestCommonSubsequence {
public:
    // Find length of LCS using DP
    int lcsLength(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    // Characters match, extend the subsequence
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    // Characters don't match, take maximum from previous states
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }

    // Get the actual LCS string using DP table
    string getLCS(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // Reconstruct the LCS
        string lcs = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                // Character is part of LCS
                lcs = s1[i-1] + lcs;
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                // Move up
                i--;
            } else {
                // Move left
                j--;
            }
        }

        return lcs;
    }

    // Print the DP table for debugging
    void printDPTable(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout << "\nDP Table:" << endl;
        cout << "    ";
        for (char c : s2) cout << c << " ";
        cout << endl;

        for (int i = 0; i <= m; i++) {
            if (i == 0) cout << "  ";
            else cout << s1[i-1] << " ";
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Driver code
int main() {
    LongestCommonSubsequence lcs;

    cout << "===== LONGEST COMMON SUBSEQUENCE =====" << endl;

    // Example 1: Basic LCS
    cout << "\n1. Basic LCS Problem:" << endl;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "LCS Length: " << lcs.lcsLength(s1, s2) << endl;
    cout << "LCS String: " << lcs.getLCS(s1, s2) << endl;

    // Print DP table for visualization
    lcs.printDPTable(s1, s2);

    // Example 2: No common subsequence
    cout << "\n2. No Common Subsequence:" << endl;
    string s3 = "ABC";
    string s4 = "XYZ";

    cout << "String 1: " << s3 << endl;
    cout << "String 2: " << s4 << endl;
    cout << "LCS Length: " << lcs.lcsLength(s3, s4) << endl;
    cout << "LCS String: \"" << lcs.getLCS(s3, s4) << "\"" << endl;

    // Example 3: One string is subsequence of another
    cout << "\n3. One string is subsequence of another:" << endl;
    string s5 = "ABCDEF";
    string s6 = "ACE";

    cout << "String 1: " << s5 << endl;
    cout << "String 2: " << s6 << endl;
    cout << "LCS Length: " << lcs.lcsLength(s5, s6) << endl;
    cout << "LCS String: " << lcs.getLCS(s5, s6) << endl;

    return 0;
}
