class Solution {
public:
    vector<int> sortedSquares(vector<int>& s) {
        vector<int> ans;
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            int a = s[i], b = s[j];
            if (s[i] < 0) {
                a = (-1) * s[i];
            }
            if (s[j] < 0) {
                b = (-1) * s[j];
            }
            if (a > b) {
                ans.push_back(a * a);
                i++;
            } else {
                ans.push_back(b * b);
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
