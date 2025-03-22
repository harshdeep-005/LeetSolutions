// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int n= intervals.size(), l=0, r=n-1, mid, tar;
//         while(l<=r){
//             mid=l+(r-l)/2;
//             if(intervals[mid][1]<tar)l=mid+1;
//             else r=mid;
//         }
//         vector<vector<int>>arr;
//         for(int i=0; i<n; i++){
//             if()
//             arr.push_back({intervals[i][0],intervals[i][1]});
//         }
//     }
// };
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
