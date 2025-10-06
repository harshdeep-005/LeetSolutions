class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0], 0, 0});
        int ans = 0;
        
        while(!pq.empty()) {
            auto v = pq.top();
            int h = v[0], x = v[1], y = v[2];
            pq.pop();
            if(visited[x][y]) continue;
            visited[x][y] = true;
            
            ans = max(ans, h);
            if(x == n-1 && y == n-1) return ans;
            
            for(auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return ans;
    }
};
