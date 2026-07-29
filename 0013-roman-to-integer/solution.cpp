class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>lis={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        char curr=s[0], next;
        int ans=0;
        for(int i=1;i<s.size();i++){
            next=s[i];
            if(lis[curr]<lis[next])ans-=lis[curr];
            else ans+=lis[curr];
            cout<<lis[curr]<<endl;
            curr=next;
        }
        return ans+lis[curr];
    }
};
