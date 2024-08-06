class Solution {
public:
    string countAndSay(int n) {
    if(n==1)
        return "1";

    int i=0;
    string s= countAndSay(n-1) ;
    string ne="";
    while(s[i]){
        int j=0, a=s[i]-48;
        while(s[i] && a==s[i]-48){
            j++;
            i++;
        }
        ne+=j+48;
        ne+=a+48;
        }
        return ne;
    }
};
