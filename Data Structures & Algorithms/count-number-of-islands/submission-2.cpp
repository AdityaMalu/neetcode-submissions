class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    trav(grid, vis, i, j, m, n);
                }
            }
        }

        return ans;
    }

    void trav(vector<vector<char>>& grid, vector<vector<int>>& vis, int sR, int sC, int m, int n) {
        vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        queue<pair<int, int>> q;
        q.push({sR, sC});
        vis[sR][sC] = 1;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int currRow = curr.first;
            int currCol = curr.second;


            for (auto [x, y] : dir) {
                if (currRow + x >= 0 && currRow + x < m && currCol + y >= 0 && currCol + y < n) {
                    if (!vis[currRow + x][currCol + y] && grid[currRow + x][currCol + y] == '1') {
                        vis[currRow + x][currCol+ y] = 1;
                        q.push({currRow + x, currCol + y});
                    }
                }
            }
        }
    }
};
