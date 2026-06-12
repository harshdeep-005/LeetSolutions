class Solution {
public:
    long long foo(vector<int>& s, int val) {
        long long total = 0;
        for (int p : s) {
            total += (p + val - 1) / val;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& s, int h) {
        sort(s.begin(), s.end());
        int l = 1, r = s[s.size() - 1], mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (foo(s, mid) > h)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
