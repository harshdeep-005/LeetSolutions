class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (matrix[i][mid] > matrix[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool leftSmaller = (mid == 0) || (matrix[maxRow][mid] > matrix[maxRow][mid - 1]);
            bool rightSmaller = (mid == n - 1) || (matrix[maxRow][mid] > matrix[maxRow][mid + 1]);

            if (leftSmaller && rightSmaller) {
                return {maxRow, mid};  
            }

            if (mid > 0 && matrix[maxRow][mid - 1] > matrix[maxRow][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return {-1, -1};  
    }
};

