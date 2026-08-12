class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = nums[0], j = nums[0];

        while (true) {
            i = nums[i];
            j = nums[nums[j]];

            if (i == j)
                break;
        }

        i = nums[0];

        while (i != j) {
            i = nums[i];
            j = nums[j];
        }

        return i;
    }
};
