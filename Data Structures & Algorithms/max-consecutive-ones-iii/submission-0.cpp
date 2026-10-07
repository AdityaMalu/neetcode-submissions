class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, cnt = k, ans = 0;
        while (end < nums.size()) {
            if (nums[end] == 1) {
                end++;
            } else {
                if (cnt > 0) {
                    end++;
                    cnt--;
                } else if (nums[start] == 1) {
                    start++;
                } else if (nums[start] == 0 && cnt == 0) {
                    start++;
                    cnt++;
                }
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};