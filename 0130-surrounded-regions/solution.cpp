class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int m=board.size(), n=board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'S';
            }
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                board[i][n - 1] = 'S';
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = 'S';
            }
            if (board[m - 1][i] == 'O') {
                q.push({m - 1, i});
                board[m - 1][i] = 'S';
            }
        }
        int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
        while(!q.empty()){
            int a=q.front().first, b=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx=a+dx[i], ny=b+dy[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(board[nx][ny]=='O'){
                    board[nx][ny]='S';
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0; i<m; i++)for(int j=0; j<n; j++)if(board[i][j]=='O')board[i][j]='X';
        for(int i=0; i<m; i++)for(int j=0; j<n; j++)if(board[i][j]=='S')board[i][j]='O';
    }
};
