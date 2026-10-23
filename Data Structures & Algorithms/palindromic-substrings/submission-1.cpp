class Solution {
   public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    ans++;
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < s.size()) {
                if (s[l] == s[r]) {
                    ans++;
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};
