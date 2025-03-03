class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false; 

        map<int, int> freq;
        for (int num : nums) freq[num]++;

        for (auto it = freq.begin(); it != freq.end(); ) {
            int start = it->first; 
            int count = it->second; 
            
            if (count > 0) {
                for (int i = 0; i < k; i++) {
                    if (freq[start + i] < count) return false; 
                    freq[start + i] -= count;
                }
            }

            while (it != freq.end() && it->second == 0) it++; 
        }

        return true;
    }
};
