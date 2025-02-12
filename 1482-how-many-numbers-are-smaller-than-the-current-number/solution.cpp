class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedNums = nums; 
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < sortedNums.size(); i++) {
            if (rank.find(sortedNums[i]) == rank.end()) {
                rank[sortedNums[i]] = i; 
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = rank[nums[i]]; 
        }

        return nums;
    }
};
