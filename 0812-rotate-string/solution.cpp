class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;
        for(int i=0; i<s.length(); i++){
            if(s==goal)return true;
            reverse(s.begin()+1,s.end());
            reverse(s.begin(),s.begin()+1);
            reverse(s.begin(),s.end());
        }
        return false;
    }
};
