class Solution {
public:
    vector<int> applyOperations(vector<int>& s) {
        for(int i=0;i<s.size()-1; i++){            
            if(s[i]==s[i+1]){
                s[i]*=2;
                s[i+1]=0;
            }
        }
        int i=0, j=0;
        while(j<s.size()){
            if(s[j]!=0){
                swap(s[i],s[j]);
                i++;
            }
            j++;
        }
        return s;
    }
};
