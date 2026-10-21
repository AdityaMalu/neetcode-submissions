class Solution {
   public:
    int recurr(string text1, string text2, int i, int j, vector<vector<int>>& dp) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int not_match1 = 0, not_match2 = 0;
        if (text1[i] == text2[j]) {
            return 1 + recurr(text1, text2, i + 1, j + 1, dp);
        } else {
            not_match1 = recurr(text1, text2, i + 1, j, dp);
            not_match2 = recurr(text1, text2, i, j + 1, dp);
        }

        return dp[i][j] = max(not_match1, not_match2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() > text2.size()) {
            string temp = text1;
            text1 = text2;
            text2 = temp;
        }
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return recurr(text1, text2, 0, 0, dp);
    }
};
