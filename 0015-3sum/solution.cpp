class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;
        int n = nums.size();
            for (int b = 0; b < n - 2; b++) {
                if (b > 0 && nums[b] == nums[b - 1]) continue;  
                
                int c = b + 1, d = n - 1;
                while (c < d) {
                    long long sum = (long long)nums[b] + nums[c] + nums[d];

                    if (sum == 0) {
                        arr.push_back({nums[b], nums[c], nums[d]});
                        
                        while (c < d && nums[c] == nums[c + 1]) c++;  
                        while (c < d && nums[d] == nums[d - 1]) d--;  
                        
                        c++;
                        d--;
                    } else if (sum < 0) {
                        c++;
                    } else {
                        d--;
                    }
                }
            }
        return arr;
    }
};



