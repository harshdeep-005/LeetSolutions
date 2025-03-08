class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> cup;
        int x=0;
        for(auto n:nums)cup[n]++;
        for(auto n:cup)if(n.second==2)x^=n.first;
        return x;
    }
};

