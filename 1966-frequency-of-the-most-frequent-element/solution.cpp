class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, maxFreq = 0;
        long long sum = 0; 

        while (r < nums.size()) {
            sum += nums[r];

            while ((long long)(r - l + 1) * nums[r] - sum > k) {
                sum -= nums[l];
                l++;
            }

            maxFreq = max(maxFreq, r - l + 1);
            r++;
        }

        return maxFreq;
    }
};

        // sort(nums.begin(), nums.end());
        // int max=0;
        // for(int i=0; i<nums.size(); i++){
        //     int j=i-1, n=0;
        //     while(n<=k&&j>=0){
        //         n+=(nums[i]-nums[j]);
        //         j--;
        //         if(max<(i-j))max=i-j;
        //     }
        // }
        // return max;
