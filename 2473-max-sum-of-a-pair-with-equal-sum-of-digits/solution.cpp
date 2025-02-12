class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> data;

        // Group numbers by sum of digits
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0, z = nums[i];
            while (z > 0) {
                sum += z % 10;
                z /= 10;
            }
            data[sum].push_back(nums[i]);
        }

        int maxSum = -1;

        
        for (auto& [key, values] : data) {
            if (values.size() >= 2) {
                sort(values.begin(), values.end(), greater<int>()); 
                int pairSum = values[0] + values[1]; 
                maxSum = max(maxSum, pairSum);
            }
        }
        return maxSum;
    }
};
