class Solution
{
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = grid[0][j];
        }
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    dp[i + 1][k] = min(dp[i][j] + moveCost[grid[i][j]][k] + grid[i + 1][k], dp[i + 1][k]);
                }
            }
        }
        int mini = dp[m - 1][0];
        for (int j = 1; j < n; j++)
        {
            mini = min(mini, dp[m - 1][j]);
        }

        return mini;
    }
};
