class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=1, l=0, r=0, maxi=nums[0];
        while(r<nums.size()){
            product*=nums[r];
            int z=0;
            while(product==0&&r<nums.size()){
                maxi=max(maxi,0);
                product=nums[r];
                r++;
                l=r;
                z=1;
            }
            r++;
            if(z==1){z--; r--;}
            maxi=max(maxi, product);
        }
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            maxi = max(maxi, product);
            if (product == 0) product = 1; 
        }
        return maxi;
    }
};

