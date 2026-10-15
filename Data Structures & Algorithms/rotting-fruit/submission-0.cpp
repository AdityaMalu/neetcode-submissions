class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();     // rows
        int n = grid[0].size();  // cols
        int ans = 0;

        queue<pair<pair<int, int>, int>> q;  // node(x,y), time
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            pair<int, int> cood = curr.first;
            int time = curr.second;
            ans = max(ans, time);

            for (auto i : directions) {
                int newX = cood.first + i.first;
                int newY = cood.second + i.second;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                    if (vis[newX][newY] == 0) {
                        q.push({{newX, newY}, time + 1});
                        grid[newX][newY] = 2;
                        vis[newX][newY] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = -1;
                }
            }
        }

        return ans;
    }
};
