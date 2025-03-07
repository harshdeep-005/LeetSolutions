class Solution {
public:
    int foo(int n){
        if(n==0)return 0;
        if(n==1)return 1;
        return foo(n-1)+foo(n-2);
    }
    int fib(int n) {
        return foo(n);
    }
};
