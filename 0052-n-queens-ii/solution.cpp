class Solution {
public:
    void foo(int row, int n, vector<vector<int>> &visit, vector<vector<string>> &ans, vector<string> &dp) {
        if (row == n) { 
            ans.push_back(dp);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (visit[row][col] == 0) { 
                
                dp[row][col] = 'Q';

                vector<vector<int>> temp = visit; 
                for (int i = 0; i < n; i++) {
                    visit[row][i] = 1;  
                    visit[i][col] = 1;  
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (abs(i - row) == abs(j - col)) { 
                            visit[i][j] = 1;
                        }
                    }
                }

                foo(row + 1, n, visit, ans, dp);

                visit = temp;
                dp[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> visit(n, vector<int>(n, 0)); 
        vector<string> dp(n, string(n, '.')); 
        foo(0, n, visit, ans, dp);
        int x=ans.size();
        return x;
    }
};
