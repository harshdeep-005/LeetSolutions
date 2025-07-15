class Solution {
public:
    int foo(int i, vector<int>& nums, vector<int>& dp) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int take = nums[i] + foo(i + 2, nums, dp);
        int skip = foo(i + 1, nums, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return foo(0, nums, dp);
    }
};


