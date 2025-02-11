class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return false;
        int x;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1])x=1;
            else x++;
            if(x>1)return true;
        }
        return false;

    }
};
