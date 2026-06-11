class Solution {
public:
    int trap(vector<int>& s) {
        int i=0,j=s.size()-1, ans=0, l=0,r=0;
        while(i<j){
            l=max(s[i],l);
            r=max(s[j],r);
            if(s[i]<s[j]){
                i++;
                if(l>s[i]) ans+=l-s[i];
                cout<<ans;
            }
            else {
                j--;
                if(r>s[j]) ans+=r-s[j];
                cout<<ans;
            }
        }
        return ans;
    }
};
