class Solution {
public:
    int recurr(int n, vector<int>& dp) {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int one = recurr(n - 1, dp);
        int two = recurr(n - 2, dp);

        dp[n] = one + two;

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        return recurr(n, dp);
    }
};