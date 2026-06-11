class Solution {
public:
    void moveZeroes(vector<int>& s) {
        int i=0, j=0;
        while(j<s.size()){
            if(s[j]!=0){
                swap(s[i],s[j]);
                i++;
            }
            j++;
        }
    }
};
