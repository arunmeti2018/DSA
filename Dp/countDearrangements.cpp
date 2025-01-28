#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solveBrute(int n) {
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;
        return (n - 1) * (solveBrute(n - 1) + solveBrute(n - 2));
    }

    int solveMemo(int n, vector<int>& dp) {
        if (n == 1)
            return 0;

        if (n == 2)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = (n - 1) * (solveMemo(n - 1, dp) + solveMemo(n - 2, dp));

        return dp[n];
    }

    int solveTab(int n) {
        if (n == 1)
            return 0;

        if (n == 2)
            return 1;

        vector<int> dp(n + 1, -1);
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }

    int solveOpt(int n) {
        if (n == 1)
            return 0;

        if (n == 2)
            return 1;

        int prev2 = 0;
        int prev1 = 1;
        for (int i = 3; i <= n; i++) {
            int ans = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
};

int main() {
    Solution sol;

    // Test cases
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Recursive brute force
    int resultBrute = sol.solveBrute(n);
    cout << "The number of derangements using brute force for n = " << n << " is: " << resultBrute << endl;

    // Memoization
    vector<int> dp(n + 1, -1);
    int resultMemo = sol.solveMemo(n, dp);
    cout << "The number of derangements using memoization for n = " << n << " is: " << resultMemo << endl;

    // Tabulation
    int resultTab = sol.solveTab(n);
    cout << "The number of derangements using tabulation for n = " << n << " is: " << resultTab << endl;

    // Space optimized
    int resultOpt = sol.solveOpt(n);
    cout << "The number of derangements using space optimization for n = " << n << " is: " << resultOpt << endl;

    return 0;
}
