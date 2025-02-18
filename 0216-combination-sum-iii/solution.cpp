class Solution {
public:
    void foo(int ind, int target, int k, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0&& k==ds.size()) {
            ans.push_back(ds); 
            return;
        }
        
        for (int i = ind; i < arr.size(); i++) {
            // if (i > ind && arr[i] == arr[i - 1]) continue; 

            if (arr[i] > target) break; 

            ds.push_back(arr[i]);
            foo(i + 1, target - arr[i], k, arr, ans, ds); 
            ds.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)  {
        vector<vector<int>> ans;
        vector<int> ds; 
        vector<int> candidates={1,2,3,4,5,6,7,8,9}; 

        foo(0, n, k, candidates, ans, ds);
        
        return ans;
    }
};


