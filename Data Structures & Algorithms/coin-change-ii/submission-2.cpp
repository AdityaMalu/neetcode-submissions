class Solution {
   public:
    int recurr(int amount, vector<int>& coins, int total, int ind, vector<vector<int>>& dp) {
        if (ind >= coins.size()) return 0;
        if (total > amount) return 0;
        if (total == amount) return 1;

        if(dp[ind][total] != -1) return dp[ind][total];

        int pick = recurr(amount, coins, total + coins[ind], ind, dp);
        int not_pick = recurr(amount, coins, total, ind + 1, dp);

        return dp[ind][total] = pick + not_pick;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return recurr(amount, coins, 0, 0, dp);
    }
};
