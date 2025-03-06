class Solution {
public:
//     bool canJump(vector<int>& nums) {
//         int x=0, i=0;
//         while(i<nums.size()-1){
//             x+=nums[i];
//             i=x;
//             if(i<nums.size()-1&&nums[i]==0)return false;
//         }
//         if(i>=nums.size()-1)return true;
//         return false;
//     }
bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; 
            maxReach = max(maxReach, i + nums[i]); 
            if (maxReach >= nums.size() - 1) return true; 
        }
        return true;
    }
};

