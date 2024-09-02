class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ne(m,vector<int>(n));
        if (m * n != original.size())
            return {};
        for(int j=0; j<m; j++){
            for(int k=0, i=j*n+k; k<n; k++, i++){
                ne[j][k]=original[i];
            }
        }
        return ne;
    }
};
