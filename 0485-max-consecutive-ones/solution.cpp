class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0, cnt=0, n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1)cnt++;
            else cnt=0;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
