class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        char a,b,c,d;
        if(s1.size()!=s2.size())return false;
        if(s1==s2)return true;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt==1){a=s1[i]; c=s2[i];}
                if(cnt==2){b=s2[i]; d=s1[i];}
            }
        }
        if((cnt==0||cnt==2)&&(a==b)&&(c==d))return true;
        return false;
    }
};
