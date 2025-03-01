class Solution {
public:
    bool canPlaceFlowers(vector<int>& x, int n) {
        int count = 0;
        if (x.size() == 1 && x[0] == 0 && n == 1) {
            count++;
        }
        if (x.size() > 1) {
            if (x[0] == 0 && x[1] == 0) {
                x[0] = 1;
                count++;
            }
        }
        if (x.size() > 2) {
            for (int i = 1; i < x.size() - 2; i++)
                if (x[i - 1] == 0 && x[i] == 0 && x[i + 1] == 0) {
                    x[i] = 1;
                    count++;
                }
        }
        if (x.size() > 1) {
            if (x[x.size() - 1] == 0 && x[x.size() - 2] == 0) {
                x[x.size() - 1] = 1;
                count++;
            }
        }
        if (count >= n)
            return true;
        return false;
    }
};
