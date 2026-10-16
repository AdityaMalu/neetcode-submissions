class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                ans++;

                trav(isConnected, vis, i, n);
            }
        }

        return ans;
    }

    void trav(vector<vector<int>>& isConnected, vector<int>& vis, int start, int n) {
        queue<int> q;

        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int city = 0; city < n; city++) {
                if (isConnected[curr][city] == 1 && vis[city] == 0) {
                    vis[city] = 1;
                    q.push(city);
                }
            }
        }
    }
};