class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        double num=log(n)/log(4);
        return(num==floor(num));
    }
};
