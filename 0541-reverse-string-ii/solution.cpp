class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0,j;
        while(i<s.length()){
            reverse(s.begin()+i,s.begin()+min(i + k, (int)s.length()));
            i+=2*k;
        }
        return s;
    }
};
