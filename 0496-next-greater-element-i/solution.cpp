// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         stack<int> s;
//         vector<int> arr={-1};
//         int i=nums2.size()-1;
//         while(i>=0){
//             if(nums2[i]<s.top())  s.push(num2[i]);
//             else
//         }
//     }
// };
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge; 
        stack<int> s;
        vector<int> result(nums1.size(), -1); 

        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                nge[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (nge.find(nums1[i]) != nge.end()) {
                result[i] = nge[nums1[i]];
            }
        }

        return result;
    }
};
