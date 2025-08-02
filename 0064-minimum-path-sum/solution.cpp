class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> v = grid;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i > 0 && j > 0) {
                    v[i][j] += min(v[i - 1][j], v[i][j - 1]);
                } else if (i == 0) {
                    v[i][j] += v[i][j - 1];
                } else if (j == 0) {
                    v[i][j] += v[i - 1][j];
                }
            }
        }
        return v[m - 1][n - 1];
    }
};
