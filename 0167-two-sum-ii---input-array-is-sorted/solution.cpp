class Solution {
public:
    vector<int> twoSum(vector<int>& s, int target) {
        int i=0, j=s.size()-1;
        vector<int> arr={0,0};
        while(i<j){
            if(s[i]+s[j]<target)i++;
            else if(s[i]+s[j]>target)j--;
            else {
                arr[0]=i+1;
                arr[1]=j+1;
                break;
            }
        }
        return arr;
    }
};
