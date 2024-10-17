class Solution {
public:
    long long minimumSteps(string s) {
        int i=0, temp=0;
        long long ans=0;
        while(s[i]!='\0'){
            if(s[i]=='0'){
                ans+=(i-temp);
                temp++;
            }
            i++;
        }
        cout<<ans;
        return ans;
    }
};
