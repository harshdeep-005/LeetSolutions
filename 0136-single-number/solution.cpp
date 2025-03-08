class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int> cup;
        // for(auto n:nums)cup[n]++;
        // for(auto n:cup)if(n.second==1)return n.first;
        // return 0;

        // if(nums.size()==1)return nums[0];
        // sort(nums.begin(),nums.end());
        // int x=nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     x^=nums[i];
        // }
        // return x;

        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x;

    }
};
