class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int m = arr.size();
        int n = arr[0].size();
        
        if (m == 0 || n == 0)
            return false;
        
        int l = 0, r = m - 1, mid = 0;
        
        while (l <= r) {
            mid = l + (r - l) / 2;  
            if (arr[mid][0] == x)  
                return true;
            if (arr[mid][0] < x && arr[mid][n - 1] >= x) {
                break;
            }
            if (arr[mid][0] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        int row = mid;
        l = 0, r = n - 1;
        
        while (l <= r) {
            int mid2 = l + (r - l) / 2; 
            if (arr[row][mid2] == x)
                return true;
            if (arr[row][mid2] < x)
                l = mid2 + 1;
            else
                r = mid2 - 1;
        }
        
        return false; 
    }
};

