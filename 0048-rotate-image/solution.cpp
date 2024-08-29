class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
    int m = mat.size();       
    int arr[m][m];
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            arr[i][j]=mat[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            mat[j][m-i-1]=arr[i][j];
        }
    }
    }
};
