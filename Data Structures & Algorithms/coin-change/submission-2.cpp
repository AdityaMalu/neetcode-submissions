class Solution {
public:
    int recurr(vector<int>& coins, int amount, int ind,
               vector<vector<int>>& dp) {

        if (amount == 0) {
            return 0;
        }

        if (amount < 0 || ind >= coins.size()) {
            return INT_MAX;
        }

        if (dp[amount][ind] != -1) {
            return dp[amount][ind];
        }

        int pick = recurr(coins, amount - coins[ind], ind, dp);

        if (pick != INT_MAX) {
            pick++;
        }

        int not_pick = recurr(coins, amount, ind + 1, dp);

        return dp[amount][ind] = min(pick, not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(
            amount + 1,
            vector<int>(coins.size(), -1)
        );

        int ans = recurr(coins, amount, 0, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};