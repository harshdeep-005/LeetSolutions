class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(),l=0,r=n-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            bool leftSmaller = (mid == 0) || (nums[mid] > nums[mid - 1]);
            bool rightSmaller = (mid == n - 1) || (nums[mid] > nums[mid + 1]);

            if (leftSmaller && rightSmaller) {
                return mid;  
            }

            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
