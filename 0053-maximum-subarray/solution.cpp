class Solution {
public:
    int sum(int arr[],int i, int j){
        int sum=0;
        for(int x=i; x<j; x++){
            sum += arr[x];
        }
        return sum;
    }

    int max(int a, int b){
        if(a>b)return a;
        else return b;
    }
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int maxSum = arr[0];
        int currentSum = arr[0];

        for (int i = 1; i < n; i++) {
            currentSum = max(arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
