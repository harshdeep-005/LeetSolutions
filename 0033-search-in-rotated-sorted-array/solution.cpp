class Solution {
public:
    int fo(int l, int r, vector<int>& s, int tar){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(s[mid]==tar)return mid;
            else if(s[mid]<tar)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
    int search(vector<int>& s, int tar) {
        int n=s.size(),l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(s[mid]>s[n-1])l=mid+1;
            else r=mid;
        }
        int rot=l;
        l=0,r=n-1;
        int ans;
        if(tar >= s[rot] && tar <= s[n-1]) ans= fo(rot,n-1,s,tar);
        else ans =fo(0,rot-1,s,tar);

        return ans;
    }
};
