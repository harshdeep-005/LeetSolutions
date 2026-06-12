class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans=0,prefix=0;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            prefix+=nums[i];
            if(mp.count(prefix-k)){
                ans+=mp[prefix-k];
                mp[prefix]++;
            }
            else mp[prefix]++;
        }
        return ans;
    }
};
