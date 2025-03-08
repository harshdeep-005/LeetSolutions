class Solution {
public:
    bool check(vector<int>& nums) {
        int i=1;
        int n=nums.size();
        if(n==1||n==2)return true;
        while(nums[i-1]<=nums[i]&&i<n){if(i==n-1)return true;i++;}
        if(i==n-1&&nums[i]>nums[0])return false;
        for(int j=i; j<n-1;j++){
            if(nums[j]>nums[j+1]||nums[j+1]>nums[0])return false;
        }
        return true;
    }
};
