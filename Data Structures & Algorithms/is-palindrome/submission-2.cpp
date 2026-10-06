class Solution {
   public:
    bool isPalindrome(string s) {
        string aplhaNumeric = makeItAplhaNumeric(s);

        int start = 0, end = aplhaNumeric.size() - 1;
        while (start <= end) {
            if (aplhaNumeric[start] == aplhaNumeric[end]) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }

    string makeItAplhaNumeric(string s) {
        string ans = "";
        for (char i : s) {
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
                ans += tolower(i);
            }
        }
        return ans;
    }
};
