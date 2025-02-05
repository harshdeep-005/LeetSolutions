class Solution {
public:
    bool buddyStrings(string s1, string s2) {
        int cnt=0;
        char a,b,c,d,z=0;
        if(s1.size()!=s2.size())return false;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt==1){a=s1[i]; c=s2[i];}
                if(cnt==2){b=s2[i]; d=s1[i];}
            }
            for(int j=i; j<s1.size(); j++){
                if(s1[i]==s1[j]&&i!=j)z=1;
            }
        }
        
        if(s1==s2){
            if(z==1)return true;
            else return false;
        }
        if((cnt==2)&&(a==b)&&(c==d))return true;
        return false;
    }
};
