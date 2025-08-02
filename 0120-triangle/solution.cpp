class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), mini;
        for(int i=0; i<m; i++){
            for(int j=0; j<=i; j++){
                if(i==0 &&j==0)continue;
                else if(j==0) triangle[i][j]+=triangle[i-1][j];
                    else if(i==j) triangle[i][j]+=triangle[i-1][j-1];
                        else triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }
        mini=triangle[m-1][0];
        for(int i=1; i<m; i++) mini=min(mini, triangle[m-1][i]);
        return mini;
    }
};
