class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int currLen = 1;
        int maxSum = nums[0];
        int currSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                currLen++;
                currSum += nums[i];
            } else {
                currLen = 1;
                currSum = nums[i];
            }
            if (currSum >= maxSum) {
                maxSum = currSum;
            }
        }

        return maxSum;
    }
};
