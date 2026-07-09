class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {false};
        bool col[9][10] = {false};
        bool block[9][10] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';          // FIX
                    row[i][val] = true;
                    col[j][val] = true;
                    int blk = (i / 3) * 3 + (j / 3);
                    block[blk][val] = true;
                }
            }
        }

        foo(row, col, block, board);
    }

    bool foo(bool row[][10], bool col[][10], bool block[][10],
             vector<vector<char>>& board) {

        int i, j;

        // Find first empty cell
        for (i = 0; i < 9; i++) {
            bool found = false;
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        // No empty cell => solved
        if (i == 9)
            return true;

        int blk = (i / 3) * 3 + (j / 3);

        for (int val = 1; val <= 9; val++) {

            if (!row[i][val] && !col[j][val] && !block[blk][val]) {

                row[i][val] = true;
                col[j][val] = true;
                block[blk][val] = true;
                board[i][j] = val + '0';

                if (foo(row, col, block, board))
                    return true;

                // Backtrack
                row[i][val] = false;
                col[j][val] = false;
                block[blk][val] = false;
                board[i][j] = '.';
            }
        }

        return false;
    }
};
