class Solution {
   public:
    bool recurr(vector<int>& nums, int rem, int tillNow, int ind, vector<vector<int>>& dp) {
        if (ind >= nums.size()) {
            return false;
        }

        if (tillNow >= rem) {
            if (tillNow == rem) return true;
            return false;
        }

        if (dp[ind][rem] != -1) return dp[ind][rem];

        bool pick = false, not_pick = false;
        pick = recurr(nums, rem - nums[ind], tillNow + nums[ind], ind + 1, dp);
        not_pick = recurr(nums, rem, tillNow, ind + 1, dp);

        return dp[ind][rem] = pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i : nums) {
            total += i;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(total + 1, -1));
        return recurr(nums, total, 0, 0, dp);
    }
};
