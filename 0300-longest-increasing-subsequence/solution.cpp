class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), maxi=0;
        vector<int> arr(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && arr[i]<arr[j]+1)arr[i]=arr[j]+1;
            }
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};
