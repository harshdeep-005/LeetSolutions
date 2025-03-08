class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(), l=0, cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cnt++;
            }
            else{
                nums[l]=nums[i];
                l++;
            }
        }
        for(int i=0; i<cnt; i++)nums[n-i-1]=0;
    }
};
