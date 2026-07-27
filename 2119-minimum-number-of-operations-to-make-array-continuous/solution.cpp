class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(), maxi=1, curr=1, l=0;
        for(int r=1;r<n;r++){
            if(nums[r]==nums[r-1])continue;
            while(nums[r]-nums[l]>n-1){
                if(nums[l]==nums[l+1]&&l<n)curr++;
                l++;
                curr--;
            }
            curr++;
            maxi=max(curr,maxi);
        }
        return (n-maxi);
    }
};
