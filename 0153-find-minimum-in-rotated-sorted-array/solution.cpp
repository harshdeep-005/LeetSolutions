class Solution {
public:
    int findMin(vector<int>& s) {
        int l=0,n=s.size(),r=n-1,mid;
        while(l<r){
            int mid=l+(r-l)/2;
            if(s[mid]>s[n-1])l=mid+1;
            else r=mid;
        }
        return s[l];
    }
};
