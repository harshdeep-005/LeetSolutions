class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long> > a;
        for(int i=0; i<nums.size(); i++)a.push(nums[i]);
        long long x,y,z;
        int  l=0;
        if(nums.size()<2)return 0;
        x=a.top();
        a.pop();
        y=a.top();
        a.pop();
        while(!(x>=k&&y>=k)){
            l++;
            z=x*2 + y;
            a.push(z);
            x=a.top();
            a.pop();
            y=a.top();
            a.pop();
        }
        return l;
    }
};
