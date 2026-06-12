class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(string p : strs){
            string a=p;
            sort(a.begin(),a.end());
            mp[a].push_back(p);
        }
        for(auto& [p, q] : mp){
            ans.push_back(q);
        }
        return ans;
    }
};
