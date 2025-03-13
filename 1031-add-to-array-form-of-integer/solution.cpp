class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> ans;
        int i = nums.size() - 1, carry = k;
        
        while (i >= 0 || carry > 0) {
            if (i >= 0) carry += nums[i--];  
            ans.push_back(carry % 10);       
            carry /= 10;                    
        }
        
        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};

