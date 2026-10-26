class Solution {
   public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;

        while (i < chars.size()) {
            char currChar = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == currChar) {
                count++;
                i++;
            }

            chars[write++] = currChar;

            if (count > 1) {
                string cnt = to_string(count);

                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};