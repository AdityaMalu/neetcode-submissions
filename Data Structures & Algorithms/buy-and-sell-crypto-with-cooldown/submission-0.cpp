class Solution {
   public:
    int recurr(vector<int>& prices, int ind, bool buy, vector<vector<int>>& dp) {
        if (ind >= prices.size()) {
            return 0;
        }

        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        if (buy) {
            return dp[ind][buy] = max(-prices[ind] + recurr(prices, ind + 1, false, dp),
                       recurr(prices, ind + 1, true, dp));
        }
        return dp[ind][buy] =  max(prices[ind] + recurr(prices, ind + 2, true, dp),
                   recurr(prices, ind + 1, false, dp));
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recurr(prices, 0, true, dp);
    }
};
