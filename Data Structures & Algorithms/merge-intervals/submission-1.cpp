class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ind = 1;
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int ind = 1; ind < intervals.size(); ind++) {
            if (intervals[ind][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[ind][1]);
            } else {
                ans.push_back(intervals[ind]);
            }
        }
        return ans;
    }
};
