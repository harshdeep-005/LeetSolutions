class Solution {
public:
    bool foo(char a){
        int s=int(a);
        if((a>=65 && a<=90)||(a>=97 && a<=122))return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        int l=0,r=s.length()-1;
        while(l<=r){
            if(foo(s[l])&&foo(s[r])){
                swap(s[l],s[r]);
                l++,r--;
                continue;
            }
            if(!foo(s[l])){
                l++;
                continue;
            }
            if(!foo(s[r])){
                r--;
                continue;
            }

        }
        return s;
    }
};
