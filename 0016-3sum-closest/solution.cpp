class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int x, diff, val=nums[0]+nums[1]+nums[2], n=nums.size(), min=std::abs(val-target);
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    x=nums[i]+nums[j]+nums[k];
                    diff=std::abs(x-target);
                    if(diff<min){
                        min=diff;
                        val=x;
                    }
                }
            }
        }
        return val;
    }
};
