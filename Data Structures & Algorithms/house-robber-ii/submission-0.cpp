class Solution {
public:
    int rob1(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];


        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);

        for(int i = 2 ; i < nums.size() ; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[nums.size()-1];
    }

    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        for(int i = 0 ; i < nums.size() ; i++){
            if (i == 0) temp1.push_back(nums[i]);
            else if(i == nums.size()-1) temp2.push_back(nums[i]);
            else{
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
        }

        return max(rob1(temp1) , rob1(temp2));
    }
};
