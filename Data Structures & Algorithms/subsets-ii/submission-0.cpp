class Solution {
   public:
    void recur(vector<int>& nums, vector<vector<int>>& ans, int ind, vector<int>& curr) {
        ans.push_back(curr);

        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);

            recur(nums, ans, i + 1, curr);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        recur(nums, ans, 0, curr);

        return ans;
    }
};