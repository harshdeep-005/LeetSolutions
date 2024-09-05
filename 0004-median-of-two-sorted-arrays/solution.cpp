class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(), n2=arr2.size(), n=n1+n2;
        int arr[n], i=0, j=0, k=0;
        while(j<n1&&k<n2){
            if(arr1[j]<arr2[k]){
                arr[i++]=arr1[j++];
            }
            else{
                arr[i++]=arr2[k++];
            }
        }
        while(j<n1){
            arr[i++]=arr1[j++];
        }
        while(k<n2){
            arr[i++]=arr2[k++];
        }
        if(n%2==0)
            return (arr[(n/2)-1]+arr[n/2])/2.0;
        else
            return arr[n/2];
    }
};
