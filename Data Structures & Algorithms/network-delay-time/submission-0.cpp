class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adjTime(n + 1);

        for (auto i : times) {
            int sourceNode = i[0];
            int targetNode = i[1];
            int timeTaken = i[2];

            adjTime[sourceNode].push_back({targetNode, timeTaken});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [time, source] = pq.top();
            pq.pop();

            if (time > dist[source]) {
                continue;
            }

            for (auto [target, timeTaken] : adjTime[source]) {

                int newTime = time + timeTaken;

                if (newTime < dist[target]) {
                    dist[target] = newTime;
                    pq.push({newTime, target});
                }
            }
        }
 
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};