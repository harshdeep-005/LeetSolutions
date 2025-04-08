class Solution {
public:
    bool foo(vector<int> nums) {
        if (nums.size() <= 1) return true;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) return false;
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        vector<int> arr(nums.begin(), nums.end());
        int count=0;
        while(!foo(arr)){
            arr.erase(arr.begin(), arr.begin() + min(3, (int)arr.size()));
            count++;
        }
        return count;
    }
};
