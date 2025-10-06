class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int x, int y) {
        visited[x][y] = 1;
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                dfs(heights, visited, nx, ny);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dfs(heights, pac, i, 0);
        for (int j = 0; j < n; j++) dfs(heights, pac, 0, j);

        for (int i = 0; i < m; i++) dfs(heights, atl, i, n-1);
        for (int j = 0; j < n; j++) dfs(heights, atl, m-1, j);

        vector<vector<int>> sol;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) sol.push_back({i, j});
            }
        }
        return sol;
    }
};
