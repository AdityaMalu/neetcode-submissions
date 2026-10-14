class Solution {
   public:
    string reorganizeString(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        priority_queue<pair<int, char>> heap;
        for (int i = 0; i < 26; i++) {
            if (count[i] > ((int)s.size() + 1) / 2) {
                return "";
            }
            if (count[i] > 0) heap.push({count[i], char('a' + i)});
        }
        string out;
        while (heap.size() >= 2) {
            auto [n1, a] = heap.top();
            heap.pop();
            auto [n2, b] = heap.top();
            heap.pop();
            out += a;
            out += b;
            if (--n1 > 0) heap.push({n1, a});
            if (--n2 > 0) heap.push({n2, b});
        }
        if (!heap.empty()) {
            out += heap.top().second;
        }
        return out;
    }
};