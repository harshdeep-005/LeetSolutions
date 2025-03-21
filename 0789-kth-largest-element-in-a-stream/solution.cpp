// class KthLargest {
// public:
//     priority_queue<int> pq1;
//     priority_queue<int, vector<int>,greater<int>> pq2;
//     KthLargest(int k, vector<int>& nums) {
//         for(int i=0; i<nums.size(); i++)pq1.push(nums[i]);
//         for(int i=0; i<k&&pq1.size()>0; i++){
//             pq2.push(pq1.top());
//             pq1.pop();
//         }
//     }
    
//     int add(int val) {
//         if(pq2.size()>0){
//             if(pq2.top()<val){
//                 pq1.push(pq2.top());
//                 pq2.pop();
//                 pq2.push(val);
//             }
//             else pq1.push(val);
//         }
//         else{
//             pq1.push(val);
//             pq2.push(val);
//         }
//         return pq2.top();

//     }
// };

// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */
 #include <queue>
#include <vector>

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; 
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top(); 
    }
};

