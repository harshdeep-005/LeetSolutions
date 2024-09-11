// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>arr;
//         for(int i=0; i<n; i++){
//             int res=1;
//             for(int j=0; j<n; j++){
//                 if(j==i)
//                     continue;
//                 res*=nums[j];
//             }
//             arr.push_back(res);
//         }
//         return arr;
//     }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1); 

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int i = n - 2; i >= 0; i--) {
            res[i] *= rightProduct * nums[i + 1];
            rightProduct *= nums[i + 1];
        }

        return res;
    }
};
