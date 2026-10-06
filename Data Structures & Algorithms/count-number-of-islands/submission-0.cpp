class Solution {
public:
    void trav(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j){

        int row = grid.size();
        int col = grid[0].size();

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        queue<pair<int,int>> que;
        que.push({i,j});
        vis[i][j] = true;

        while(!que.empty()){
            auto top = que.front();
            que.pop();

            int x = top.first;
            int y = top.second;

            for(int k = 0 ; k < 4 ; k++){
                int nrow = x + drow[k];
                int ncol = y + dcol[k];

                if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                        vis[nrow][ncol] = true;
                        que.push({nrow,ncol});
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        int ans = 0;

        for (int i = 0 ; i < row ; i++){
            for(int j = 0; j < col ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    ans++;
                    trav(grid,vis,i,j);
                }
            }
        }

        return ans;

    }
};
