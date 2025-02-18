class Solution {
public:
    void foo(int ind, vector<int>&ds,vector<vector<int>>& ans, vector<int>nums){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        foo(ind+1,ds,ans,nums);
        ds.pop_back();
        foo(ind+1,ds,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> ds;
        foo(0,ds,ans,nums);
        return ans;
    }
};
