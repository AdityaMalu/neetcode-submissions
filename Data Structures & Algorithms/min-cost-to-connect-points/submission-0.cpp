class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(n, 0);

        pq.push({0, 0});

        int totalCost = 0;
        int count = 0;

        while (!pq.empty() && count < n) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (vis[node]) {
                continue;
            }

            vis[node] = 1;
            totalCost += cost;
            count++;

            for (auto [neighbor, edgeCost] : graph[node]) {
                if (!vis[neighbor]) {
                    pq.push({edgeCost, neighbor});
                }
            }
        }

        return totalCost;
    }
};