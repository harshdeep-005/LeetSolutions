class Solution {
public:
    int maxi(int a, int b){
       if(a>b) return a;
        return b;
    }

    int maxJump(vector<int>& stones) {
        int n=stones.size(), m=0, prev1=0, prev2=0;
        for(int i=1; i<=n; i=i+2){
            if(i<n){
                m=maxi(m, stones[i]-prev1);
            }
            m=maxi(m, stones[i-1]-prev2);
            prev1=stones[i];
            prev2=stones[i-1];
        }
        return m;
    }
};
