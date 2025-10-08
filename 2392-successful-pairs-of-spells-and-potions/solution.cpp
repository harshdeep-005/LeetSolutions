class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n=spells.size();            
        long long val;
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            val=(success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(),potions.end(),val);
            ans[i]= potions.end()-it;
        }
        return ans;
    }
};
