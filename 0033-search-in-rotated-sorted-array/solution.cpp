class Solution {
public:
    int search(vector<int>& nums, int target) {
        int x=nums.size(), i;
        for (i = 0; i<x; i++){
            if(target==nums[i])
                return i;
        }
        return -1;
    }
};
