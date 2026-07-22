class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,-1);
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        arr[0]=nums[0],arr[1]=nums[1],arr[2]=nums[0]+nums[2];
        for(int i=3;i<n;i++){
            arr[i]=nums[i]+max(arr[i-2],arr[i-3]);
        }
        return max(arr[n-1],arr[n-2]);
    }
};
