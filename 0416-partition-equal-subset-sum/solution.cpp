class Solution {
public:
    bool foo(int i, vector<int>&nums,int sum, vector<vector<int>>& dp){
        if(sum==0)return true;
        if(i>=nums.size()||sum<0)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool take= foo(i+1,nums, sum, dp);
        bool ntake=foo(i+1,nums, sum-nums[i], dp);
        return dp[i][sum]=take||ntake;
    }
    bool canPartition(vector<int>& nums) {

        int sum=0;
        for(auto num : nums){
            sum+=num;
        }
        if(sum%2!=0)return false;
        vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));
        bool ans=foo(0,nums,sum/2,dp);
        return ans;
    }
};
