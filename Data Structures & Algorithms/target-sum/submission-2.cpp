class Solution {
   public:
    int recurr(vector<int>& nums, int target, int tillNow, int ind, vector<vector<int>>& dp,
               int total) {
        if (ind == nums.size()) {
            return tillNow == target ? 1 : 0;
        }

        if (dp[ind][tillNow + total] != -1) {
            return dp[ind][tillNow + total];
        }

        int add = recurr(nums, target, tillNow + nums[ind], ind + 1, dp, total);
        int subs = recurr(nums, target, tillNow - nums[ind], ind + 1, dp, total);

        return dp[ind][tillNow + total] = add + subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;

        for (int i : nums) {
            total += i;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(total * 2+1, -1));
        return recurr(nums, target, 0, 0, dp, total);
    }
};
