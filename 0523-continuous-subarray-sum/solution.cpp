class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefix=0, las=0;
        mp[0]=-1;
        if(nums.size()<2)return false;
        for(int i=0 ; i<nums.size(); i++){
            prefix+=nums[i];
            if(mp.count(prefix % k)){
                if(i-mp[prefix % k]>=2){
                return true;}
            }
            else
            mp[prefix % k]=i;
        }
        return false;
    }
};
