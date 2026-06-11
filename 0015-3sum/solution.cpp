class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res={0,0,0};
        for(int i=0; i<nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j=i+1, k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]<-nums[i])j++;
                else if(nums[j]+nums[k]>-nums[i])k--;
                else {
                    res[0]=nums[i];
                    res[1]=nums[j];
                    res[2]=nums[k];
                    ans.push_back(res);
                    // break;
                    j++;
                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};
