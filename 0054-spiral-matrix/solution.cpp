class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int i=0, j=0, a=0, b=0;
        int m=arr.size(), n=arr[0].size(), x=1, y=m*n, u=m, v=n;
        vector<int> ar;
        while(x<=y){
            for(j=b; j<n; j++){
                ar.push_back(arr[i][j]);
                x++;
            }
            if(x>y)
                break;
            j--;
            for(i=i+1; i<m; i++){
                ar.push_back(arr[i][j]);
                x++;
            }
            if(x>y)
                break;
            i--;
            for(j=j-1; j>b; j--){
                ar.push_back(arr[i][j]);
                x++;
            }
            if(x>y)
                break;
            for(i=i; i>a; i--){
                ar.push_back(arr[i][j]);
                x++;
            }
            if(x>y)
                break;
            b++;
            i++;
            j++;
            a++;
            m--;
            n--;
        }

        return ar;
    }
};
