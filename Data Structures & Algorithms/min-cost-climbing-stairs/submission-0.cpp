class Solution {
   public:
    int recurr(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = cost[i] + min(recurr(cost, i + 1, dp), recurr(cost, i + 2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() , -1);
        return min(recurr(cost, 0, dp), recurr(cost, 1, dp)); 
        }
};
