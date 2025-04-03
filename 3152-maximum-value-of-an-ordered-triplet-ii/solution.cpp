class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxTriplet = 0;

        int maxPrefix = nums[0];  
        vector<int> maxSuffix(n); 

        maxSuffix[n - 1] = nums[n - 1];
        for (int k = n - 2; k >= 0; --k) {
            maxSuffix[k] = max(maxSuffix[k + 1], nums[k]);
        }

        for (int j = 1; j < n - 1; ++j) {
            long long diff = maxPrefix - nums[j]; 
            maxTriplet = max(maxTriplet, diff * (long long)maxSuffix[j + 1]);

            maxPrefix = max(maxPrefix, nums[j]); 
        }

        return maxTriplet;
    }
};

