class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long m=0;
        for(auto a:s){if(c==a)m++;}
        return m*(m+1)/2;
    }
};
