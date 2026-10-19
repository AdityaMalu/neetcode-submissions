class Solution {
   public:
    int recurr(string& s, int ind, vector<int>& dp) {
        if (ind == s.size()) {
            return 1;
        }

        if (s[ind] == '0') {
            return 0;
        }

        if (dp[ind] != -1) {
            return dp[ind];
        }

        int one = recurr(s, ind + 1, dp);

        int two = 0;

        if (ind + 1 < s.size()) {
            int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');

            if (num <= 26) {
                two = recurr(s, ind + 2, dp);
            }
        }

        return dp[ind] = one + two;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return recurr(s, 0, dp);
    }
};