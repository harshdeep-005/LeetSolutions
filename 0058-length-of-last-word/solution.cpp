class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,i;
        for(i=s.length()-1;i>=0;i--){
            if(s[i]!=' ')break;
        }
        for(i;i>=0;i--){
            if(s[i]==' ')return ans;
            ans++;
        }
        return ans;
    }
};
