class Solution {
public:
    int foo(int i, vector<int>& nums, vector<int>& dp, int n) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int take = nums[i] + foo(i + 2, nums, dp, n);
        int skip = foo(i + 1, nums, dp, n);

        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size(), maxi;
        vector<int> dp(n,-1);
        vector<int> dp1(n,-1);
        if(n==1)return nums[0];
        return max(foo(0, nums, dp, n-1),foo(1, nums, dp1, n));

    }
};
