class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>x;
        int n=pref.size();
        x.push_back(pref[0]);
        for(int i=1; i<n; i++)x.push_back(pref[i]^pref[i-1]);
        return x;
    }
};
