class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double logResult = log10(n) / log10(2);
        return logResult == floor(logResult);
    }
};
