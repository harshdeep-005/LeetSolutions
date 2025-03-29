class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        queue<pair<int,int>>q;
        int m=board.size(), n=board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 1) {
                q.push({i, 0});
                board[i][0] = 2;
            }
            if (board[i][n - 1] == 1) {
                q.push({i, n - 1});
                board[i][n - 1] = 2;
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 1) {
                q.push({0, i});
                board[0][i] = 2;
            }
            if (board[m - 1][i] == 1) {
                q.push({m - 1, i});
                board[m - 1][i] = 2;
            }
        }
        int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
        while(!q.empty()){
            int a=q.front().first, b=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx=a+dx[i], ny=b+dy[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(board[nx][ny]==1){
                    board[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
        }
        int cnt=0;
        for(int i=0; i<m; i++)for(int j=0; j<n; j++)if(board[i][j]==1)cnt++;
        for(int i=0; i<m; i++)for(int j=0; j<n; j++)if(board[i][j]==2)board[i][j]=1;
        return cnt;
    }
};
