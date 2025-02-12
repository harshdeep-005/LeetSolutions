class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j=1;
        for(int i=0; i<arr.size(); ){
            if(arr[i]==j)i++;
            else k--;
            if(k==0)return j;
            j++;
        }
        j+=k;
        return j-1;
    }
};
