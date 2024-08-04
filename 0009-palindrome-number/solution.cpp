class Solution {
public:
    bool isPalindrome(int a) {
    long long num1 = a, num2 = 0;
    int dig;
    if (a < 0){
        return false;
    }
    while (num1 > 0) {
        dig = num1 % 10;   
        // if((a > INT_MAX / 10) || (a < INT_MIN / 10)){
        //     return false;
        // } 
        num2 = num2 * 10 + dig;
        num1 = num1 / 10;
    }
    if (a == num2 || a==0){
        return true;
    }
    else{
        return false;
    }
    }
};


