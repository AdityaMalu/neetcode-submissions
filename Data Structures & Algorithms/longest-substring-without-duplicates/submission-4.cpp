class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> uniqueElements;
        int start = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            while (uniqueElements.find(s[i]) != uniqueElements.end()) {
                uniqueElements.erase(s[start]);
                start++;
            }

            uniqueElements.insert(s[i]);
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
