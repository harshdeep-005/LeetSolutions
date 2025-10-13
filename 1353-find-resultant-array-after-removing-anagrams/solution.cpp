class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string> ans,dup;
        for(int i=0; i<n; i++){
            dup.push_back(words[i]);
            sort(words[i].begin(),words[i].end());
        }
        ans.push_back(dup[0]);
        int i=1, j=0;
        while(i<n){
            if(words[j]==words[i]){
                i++;
            }
            else{
                j=i;
                ans.push_back(dup[j]);
                i++;
            }
        }
        return ans;
    }
};
