class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int j = 0, ans = INT_MIN, curr = 0;
        while (j < nums.size()) {
            curr += nums[j];
            ans = max(curr, ans);
            if (curr < 0) {
                curr = 0;
            }
            j++;
        }
        return ans;
    }
};
