class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size(), req, add, rem, sum=0;
        vector<int>arr(n,1);
        for(int i=0; i<m; i++){
            sum+=rolls[i];
        }
        req=(mean*(m+n)-sum);
        if(req<n*1||req>n*6){
            vector<int>a;
            return a;
        }
        else{    
            req=req-n;
            for(int i=0; i<n; i++){
                add=req/(n-i);
                arr[i]+=add;
                req-=add;
            }
        }
        return arr;
    }   
};
