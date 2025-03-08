class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> cup;
        for(auto n:nums)cup[n]++;
        for(auto n:cup)if(n.second==1)return n.first;
        return 0;
    }
};
