// class Solution {
// public:
//     bool foo(string s, long long i){
//         if(i==s.size()) return true;
//         if(i%2==0){
//             if(s[i] - '0'%2==0)return foo(s,i+1);
//             else return false;
//         }
//         else{
//             if(s[i] - '0'==2||s[i] - '0'==3||s[i] - '0'==5||s[i] - '0'==7)return foo(s,i+1);
//             else return false;
//         }
//     }
//     int countGoodNumbers(long long n) {
//         long long count=0;
//         for(long long i=pow(10,n-1); i<pow(10,n); i++){
//             string s=to_string(i);
//             if(foo(s,0))count++;
//         }
//         return count;
//     }
// };


class Solution {
public:
    const int MOD = 1e9+7;

    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // ceil(n/2)
        long long oddCount = n / 2;        // floor(n/2)
        return (power(5, evenCount) * power(4, oddCount)) % MOD;
    }
};

