class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        cout<<int('A')<<" "<<int('a');
        for(char a:s){
            if(int(a)>=65&&int(a)<=90)ans+=char(int(a)+32);
            else ans+=a;
        }
        return ans;
    }
};
