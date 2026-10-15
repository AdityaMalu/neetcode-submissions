class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int currColor = image[sr][sc];

        if (currColor == color) return image;

        vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : dir) {
                int nxtRow = row + dr;
                int nxtCol = col + dc;

                if (nxtRow >= 0 && nxtRow < m && nxtCol >= 0 && nxtCol < n &&
                    image[nxtRow][nxtCol] == currColor) {
                    image[nxtRow][nxtCol] = color;
                    q.push({nxtRow, nxtCol});
                }
            }
        }

        return image;
    }
};