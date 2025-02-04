class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int currLen = 1;
        int prev = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > prev) {
                currLen++;
            } else if (nums[i] < prev) {
                currLen = 1;
            } else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
            prev = nums[i];
        }

        currLen = 1;
        prev = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < prev) {
                currLen++;
            } else if (nums[i] > prev) {
                currLen = 1;
            } else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
            prev = nums[i];
        }

        return maxLen;
    }
};
