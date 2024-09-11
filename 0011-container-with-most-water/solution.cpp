// class Solution {
// public:
//     int maxArea(vector<int>& arr) {
        
//         int max=0, ar=0, n=arr.size();
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 if(arr[i]>arr[j])
//                     ar=arr[j]*(j-i);
//                 else
//                     ar=arr[i]*(j-i);
//                 if(ar>max)
//                     max=ar;
//             }
//         }
//         return max;
//     }
// };
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;        
    }
};
