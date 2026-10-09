class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;

        stack<int> stk;

        int ind = nums2.size() - 1;
        while (ind >= 0) {
            if (stk.empty()) {
                mp[nums2[ind]] = -1;
                stk.push(nums2[ind]);
            } else {
                if (stk.top() <= nums2[ind]) {
                    stk.pop();
                    continue;
                }
                mp[nums2[ind]] = stk.top();
                stk.push(nums2[ind]);
            }
            ind--;
        }

        vector<int> ans;
        for (int i : nums1) {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};