class Solution {
public:
    int countValidPrefixes(string s) {
        int z=0,y=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')z++;
            else y++;
            if(abs(z-y)<2)ans++;
        }
        return ans;
    }
};
