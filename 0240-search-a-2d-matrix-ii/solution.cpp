class Solution {
public:
    int foo(int l, int r, vector<vector<int>>& arr, int i, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (arr[i][mid] == target) return mid;
            if (arr[i][mid] < target)
                l = mid + 1; 
            else
                r = mid - 1;  
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1; 
            if (foo(l, r, matrix, i, target) != -1) return true;
        }
        return false;
    }
};

