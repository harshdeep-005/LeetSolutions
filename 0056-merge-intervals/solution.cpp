class Solution {
public:
    void foo(int &i, vector<vector<int>>& arr, vector<vector<int>>& intervals) {
        vector<int> mergedInterval(2);
        mergedInterval[0] = intervals[i][0];
        mergedInterval[1] = intervals[i][1];

        while (i < intervals.size() - 1 && mergedInterval[1] >= intervals[i + 1][0]) {
            mergedInterval[1] = max(mergedInterval[1], intervals[i + 1][1]);
            i++;  
        }
        
        arr.push_back(mergedInterval);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> arr;
        int n = intervals.size(), i = 0;

        sort(intervals.begin(), intervals.end());

        while (i < n) {
            foo(i, arr, intervals);
            i++; 
        }

        return arr;
    }
};

