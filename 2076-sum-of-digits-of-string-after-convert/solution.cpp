class Solution {
public:
    int getLucky(string s, int k) {
        int i=0, a=0;
        int c, num=0;
        for(i=0; i<s.length(); i++){
            c=s[i]-96;
            while(c>0){
                a+=c%10;
                c/=10;
            }
        }
        while(k>1){
            num=0;
            while(a>0){
                num+=a%10;
                a/=10;
            }
            a=num;
            k--;
        }
        return a;
    }
};
