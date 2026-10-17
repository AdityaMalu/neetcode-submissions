class Solution {
public:

    void recur(vector<int>& nums, vector<vector<int>>& ans, vector<bool>& pick, vector<int>& curr){
        if(nums.size() == curr.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size() ; i++){
            if(!pick[i]){
                curr.push_back(nums[i]);
                pick[i] = true;
                recur(nums, ans, pick, curr);
                pick[i] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> pick(nums.size(), false);
        recur(nums,ans,pick, curr);
        return ans;
    }
};
