class Solution {
public:
    int reverse(int a) {
    int dig, num=0;
    while(a!=0){
        dig=a%10;
        if ((num > INT_MAX / 10) || (num < INT_MIN / 10)) {
            return 0;
        }        
        num= num*10 + dig;
        a=a/10;
    }   
    a=num;
    return a;
    }
};
