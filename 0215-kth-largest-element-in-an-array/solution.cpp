// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         unordered_map<int, int> x;
//         priority_queue<int> heap;
//         for(auto i:nums){
//             x[i]++;
//             if(x[i]==1)heap.push(i);
//         }
//         int ans;
//         int i=0;
//         while (i<k) {
//             ans=heap.top();
//             heap.pop();
//             i++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());  
        while (--k > 0) {
            maxHeap.pop();
        }

        return maxHeap.top();  
    }
};

