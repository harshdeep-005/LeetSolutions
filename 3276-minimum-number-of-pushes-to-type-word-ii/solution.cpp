class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(char w:word){
            mp[int(w)-97]++;
        }
        sort(mp.begin(),mp.end());
        reverse(mp.begin(),mp.end());
        int ans=0,j=0;
            for(int i=0;i<26;i++){
                if(i%8==0)j++;
                if(mp[i]==0)return ans;
                ans+=mp[i]*j;
            }
        return ans;
    }
};
