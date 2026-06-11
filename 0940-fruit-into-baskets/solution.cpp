class Solution {
public:
    int totalFruit(vector<int>& s) {
        int i=0,j=0,maxi=0;
        unordered_map<int,int> p;
        while(j<s.size()){
            p[s[j]]++;
            while(p.size()>2){
                p[s[i]]--;
                if(p[s[i]]==0){
                    p.erase(s[i]);
                }
                i++;
            }
            maxi=max(j-i+1,maxi);
            j++;
        }
        return maxi;
    }
};
