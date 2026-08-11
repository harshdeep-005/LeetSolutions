class Solution {
public:
    void foo(vector<int>& nums, int target, int i, int val,int & c){
        if(i==nums.size()){
            if(target==val)c++;
            return;
        }
        val+=nums[i];
        foo(nums,target,i+1,val,c);
        val-=2*nums[i];
        foo(nums,target,i+1,val,c);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        foo(nums,target,0,0,ans);
        return ans;
    }
};
