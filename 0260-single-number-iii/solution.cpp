class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>x;
        unordered_map<int,int> cup;
        for(auto n:nums)cup[n]++;
        for(auto n:cup)if(n.second==1)x.push_back(n.first);
        return x;
    }
};
