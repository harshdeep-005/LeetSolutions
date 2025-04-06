class Solution {
public:
    bool foo(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(!foo(nums)){
            int a, b, mini=INT_MAX;
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i]+nums[i+1]<mini){
                    mini=nums[i]+nums[i+1];
                    a=i,b=i+1;
                }
            }
            nums[a]=nums[a]+nums[b];
            if (b >= 0 && b < nums.size()) {
                nums.erase(nums.begin() + b);
                count++;
            }
        }
        return count;
    }
};
