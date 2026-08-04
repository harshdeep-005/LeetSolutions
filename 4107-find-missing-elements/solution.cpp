class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i - 1] + 1;

            while (val < nums[i]) {
                ans.push_back(val);
                val++;
            }
        }

        return ans;
    }
};
