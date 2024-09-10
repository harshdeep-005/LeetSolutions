class Solution {
public:
    vector<vector<int>> generateMatrix(int w) {
        int i=0, j=0, a=0, b=0;
        int m=w, n=m, x=1, y=m*n, u=m, v=n;
        int arr[m][n];
        vector<vector<int>> ar(m, vector<int>(n));
        while(x<=y){
            for(j=b; j<n; j++){
                arr[i][j]=x;
                x++;
                if(x>y)
                    break;
            }
            j--;
            for(i=i+1; i<m; i++){
                arr[i][j]=x;
                x++;
                if(x>y)
                    break;
            }
            i--;
            for(j=j-1; j>b; j--){
                arr[i][j]=x;
                x++;
                if(x>y)
                    break;
            }
            for(i=i; i>a; i--){
                arr[i][j]=x;
                x++;
                if(x>y)
                    break;
            }
            b++;
            i++;
            j++;
            a++;
            m--;
            n--;
        }
        
        for(int i=0; i<u; i++){
            for(int j=0; j<v; j++){
                ar[i][j]=arr[i][j];
            }
        }
        return ar;
    }
};
