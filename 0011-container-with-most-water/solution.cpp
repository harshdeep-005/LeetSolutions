class Solution {
public:
    int maxArea(vector<int>& s) {
        int l=0, r=s.size()-1,maxi=0;
        while(l<r){
            int cs=min(s[l],s[r]);
            int curr=(r-l)*cs;
            maxi=max(curr,maxi);
            if(s[l]<s[r])l++;
            else r--;
        }
        return maxi;

    }
};
