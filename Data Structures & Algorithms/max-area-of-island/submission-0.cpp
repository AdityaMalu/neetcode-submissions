class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    int area = trav(grid, vis, i, j, m, n);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }

    int trav(vector<vector<int>>& grid, vector<vector<int>>& vis, int sR, int sC, int m, int n) {
        vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        queue<pair<int, int>> q;

        int area = 0;

        q.push({sR, sC});
        vis[sR][sC] = 1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            area++;

            int currRow = curr.first;
            int currCol = curr.second;

            for (auto [x, y] : dir) {
                int nr = currRow + x;
                int nc = currCol + y;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return area;
    }
};