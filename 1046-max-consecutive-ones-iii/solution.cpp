class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        vector<int> a;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                count++;
            else {
                if (count > 0)
                    a.push_back(count);
                a.push_back(0);
                count = 0;
            }
        }
        if (count > 0) {
            a.push_back(count);
        }
        int r = 0, l = 0, maxi = 0, sum = 0, n = 0;
        while (r < a.size()) {
            sum += a[r];
            if (a[r] == 0) {
                sum++;
                n++;
            }
            while (n > k) {
                if (a[l] == 0) {
                    n--;
                    sum--;
                }
                sum -= a[l];
                l++;
            }
            maxi = max(sum, maxi);
            r++;
        }

        return maxi;
    }
};
