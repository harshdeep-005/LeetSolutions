class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        bool found = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j]=2;
                    found = true;
                    break; 
                }
            }
            if (found) break;
        }
        int full=0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()){
            int a=q.front().first, b=q.front().second;
            q.pop();
            int peri=4;
            for(int i=0; i<4; i++){
                int nsr=a+dx[i], nsc=b+dy[i];
                if (nsr < 0 || nsc < 0 || nsr >= m || nsc >= n || grid[nsr][nsc] == 0 ) {
                    full++;
                }
                else if (grid[nsr][nsc] == 1) {
                    q.push({nsr, nsc});
                    grid[nsr][nsc] = 2; 
                }
            }
        }
        return full;
    }
};
