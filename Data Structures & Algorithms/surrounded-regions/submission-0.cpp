class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> vis(row, vector<int>(col , 0));

        vector<pair<int,int>> dir = {{1,0} , {-1, 0} , {0,1} , {0,-1}};

        queue<pair<int,int>> q;

        for(int i = 0 ; i < col ; i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                vis[0][i] = 1;
            }

            if(board[row-1][i] == 'O'){
                q.push({row-1, i});
                vis[row-1][i] = 1;
            }
        }

        for(int i = 1 ; i < row-1 ; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = 1;
            }

            if(board[i][col-1] == 'O'){
                q.push({i, col-1});
                vis[i][col-1] = 1;
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int currX = curr.first;
            int currY = curr.second;

            for(auto [x,y] : dir){
                int nextX = currX + x;
                int nextY = currY + y;

                if(nextX >= 0 && nextX < row && nextY >=0 && nextY < col and board[nextX][nextY] == 'O'){
                    if(vis[nextX][nextY] == 0){
                        vis[nextX][nextY] = 1;
                        q.push({nextX, nextY});
                    }
                }
            }
        }

        for(int i = 0 ; i < row ; i++){
            for(int j =0 ; j < col ; j++){
                if(vis[i][j] ==0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};
