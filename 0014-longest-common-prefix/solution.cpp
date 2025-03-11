class Solution {
public:
    int min(int a, int b){
        if(a>b)return b;
        return a;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        string pre="";
        bool move=true;
        int mini=200;
        for(int i=0; i<strs.size(); i++)mini=min(mini,strs[i].size());
        for(int j=0; j<mini; j++){
            int i=0;
            while(move==true&& i< strs.size()-1){
                if(strs[i][j]!=strs[i+1][j]){
                    move=false;
                    break;
                }
                i++;
            }
            if(move==false)break;
            else pre+=strs[0][j];
        }
        return pre;
    }
};
