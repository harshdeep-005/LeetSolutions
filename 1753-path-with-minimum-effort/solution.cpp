class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (n == 1 && m == 1) return 0;  
        
        vector<vector<int>> dist(n, vector<int>(m, 1e7));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});  

        vector<int> drow = {0, 1, -1, 0};
        vector<int> dcol = {1, 0, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1) return effort;

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEffort = max(effort, abs(grid[row][col] - grid[nrow][ncol]));

                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;  
    }
};
