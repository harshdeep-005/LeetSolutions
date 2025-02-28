class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0, right=n-1, l_max=0, r_max=0, res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=l_max) l_max=height[left];
                else res+=l_max-height[left];
                left++;
            }
            else{
                if(height[right]>=r_max) r_max=height[right];
                else res+=r_max-height[right];
                right--;
            }
        }
        return res;
    }
};
