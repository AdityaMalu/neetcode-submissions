class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for (char t : tasks) count[t - 'A']++;
        int maxFreq = *max_element(count, count + 26);
        int countMax = 0;
        for (int c : count)
            if (c == maxFreq) countMax++;
        int frames = (maxFreq - 1) * (n + 1) + countMax;
        return max((int)tasks.size(), frames);
    }
};
