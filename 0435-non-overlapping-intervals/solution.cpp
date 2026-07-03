class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inte) {

        sort(inte.begin(), inte.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int ans = 0;
        int end = inte[0][1];

        for (int i = 1; i < inte.size(); i++) {
            if (inte[i][0] < end) {
                ans++;
            } else {
                end = inte[i][1];
            }
        }

        return ans;
    }
};
