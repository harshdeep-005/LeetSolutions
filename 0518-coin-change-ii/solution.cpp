class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> arr=vector<vector<unsigned long long>> (n+1,vector<unsigned long long>(amount+1,0));
        for(int i=0;i<n+1;i++)arr[i][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=amount;j++){
                if(j>=coins[i-1])arr[i][j]=arr[i-1][j]+arr[i][j-coins[i-1]];
                else arr[i][j]=arr[i-1][j];
            }
        }
        
        return arr[n][amount];
    }
};
