// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n==0)return false;
//         if(n==1)return true;
//         int x=3;
//         while(x<n){
//             x*=3;
//             cout<<x<<" ";
//         }
//         if(x==n)return true;
//         return false;
//     }
// };
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double logResult = log10(n) / log10(3);
        return logResult == floor(logResult);
    }
};

