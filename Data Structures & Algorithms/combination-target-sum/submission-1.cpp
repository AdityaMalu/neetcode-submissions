class Solution {
public:

    void recur(vector<int> & nums, int ind, vector<vector<int>>& ans, vector<int>& curr, int target){
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0 || ind == nums.size()) {
            return;
        }

        curr.push_back(nums[ind]);
        recur(nums, ind, ans, curr, target-nums[ind]);
        curr.pop_back();
        recur(nums, ind+1, ans, curr, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int ind = 0; 
        vector<int> curr;
        recur(nums, ind, ans, curr, target);
        return ans;
    }
};
