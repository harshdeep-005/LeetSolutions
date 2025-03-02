class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++)pq.push(nums[i]);
        for(int i=0; i<k-1; i++){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        return pq.top();
    }
};
