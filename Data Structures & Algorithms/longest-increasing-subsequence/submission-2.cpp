class Solution {
   public:
    int recurr(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return 0;
        }

        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        // Skip
        int notPick = recurr(nums, ind + 1, prev, dp);

        // Pick
        int pick = 0;

        if (prev == -1 || nums[ind] > nums[prev]) {
            pick = 1 + recurr(nums, ind + 1, ind, dp);
        }

        return dp[ind][prev + 1] = max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return recurr(nums, 0, -1, dp);
    }
};