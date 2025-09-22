class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto i:nums){
            count[i]++;
        }
        int maxi =0;
        for(auto j:count){
            if(j.second>maxi)
                maxi=j.second;
        }
        int m=0;
        for(auto j:count){
            if(j.second==maxi)
               m++; 
        }
        return maxi*m;
    }
};
