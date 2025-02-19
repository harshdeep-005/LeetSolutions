class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> unmap;
        int majority = nums[0], maxCount = 0;
        
        for (int num : nums) {
            unmap[num]++;  
            if (unmap[num] > maxCount) {
                maxCount = unmap[num];
                majority = num;
            }
        }
        
        return majority;
    }
};
