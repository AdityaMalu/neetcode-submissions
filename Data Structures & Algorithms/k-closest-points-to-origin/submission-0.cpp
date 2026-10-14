class Solution {
   public:
    static int dist(vector<int>& point) { return point[0] * point[0] + point[1] * point[1]; }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int> a, vector<int> b) { return dist(a) < dist(b); };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);

        for (auto i : points) {
            q.push(i);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<vector<int>> ans;

        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }

        return ans;
    }
};
