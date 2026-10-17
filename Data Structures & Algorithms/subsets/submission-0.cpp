class Solution {
   public:
    void recur(vector<int>& nums, vector<vector<int>>& ans, int ind, vector<int>& curr) {
        if (ind == nums.size()) {
            ans.push_back(curr);
            return;
        }

        recur(nums, ans, ind + 1, curr);
        curr.push_back(nums[ind]);
        recur(nums, ans, ind + 1, curr);
        curr.pop_back();
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int ind = 0;
        vector<int> curr;
        recur(nums, ans, ind, curr);
        return ans;
    }
};
