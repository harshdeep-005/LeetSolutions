class Solution {
public:
    vector<int> twoSum(vector<int>& s, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.find(target-s[i])!=mp.end())return {mp[target-s[i]],i};
            else mp[s[i]]=i;
        }
        return {};
    }
};
