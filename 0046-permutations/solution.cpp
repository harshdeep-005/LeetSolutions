class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<bool> arr(n,true);
        vector<int> res;
        foo(ans,nums,res,arr);
        return ans;
    }
    void foo(vector<vector<int>> &ans, vector<int>& nums, vector<int> &res, 
        vector<bool> &arr){
        if(res.size()==nums.size()){ans.push_back(res);return;}
        for(int i=0; i<nums.size(); i++){
            if(arr[i]){
                res.push_back(nums[i]);
                arr[i]=false;
                foo(ans,nums,res,arr);
                arr[i]=true;
                res.pop_back();
            }
        }
    }
};
