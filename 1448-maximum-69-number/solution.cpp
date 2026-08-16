class Solution {
public:
    int maximum69Number (int num) {
        int i;
        string s;
        while(num){
            i=num%10;
            num=num/10;
            s+=char(i+48);
        }
        string n="";
        bool t=1;
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        for(auto c:s){
            if(c=='6'&& t){n+="9"; t=0;}
            else n+=c;
        }
        cout<<n;
        int ans=0;
        for(auto c:n){
            ans=ans*10+int(c)-48;
        }
        return ans;
    }
};
