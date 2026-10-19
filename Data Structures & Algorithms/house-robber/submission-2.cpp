class Solution {
public:
    int recurr(vector<int>& nums, int ind, int& ans, vector<int> &dp){
        if(ind >= nums.size()){
            return 0;
        }   

        if(dp[ind] != -1){
            return dp[ind];
        }

        int rob = nums[ind] + recurr(nums, ind+2, ans, dp);
        int not_rob = recurr(nums, ind+1 , ans, dp);
        ans = max(rob, not_rob);
        dp[ind] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size() , -1);
        ans = recurr(nums, 0, ans, dp);
        return ans;
        
    }
};
