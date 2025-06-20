// class Solution {
// public:
//     void foo(vector<int>&stones, vector<int> dp, bool& ans, int k){
//         if(k==stones.size()){
//             ans=true;
//             return;
//         }
//         for(int i=-1; i<2; i++){ 
//             if(dp[k]+i>0){
//                 int target = dp[k]+i;

//                 auto it = find(stones.begin(), stones.end(), target);

//                 if (it != stones.end()) {
//                     int index = it - stones.begin();
//                     dp[index]=target;
//                     foo(stones, dp, ans, index);
//                 }
//             }
//         }
//         return;
//     }
//     bool canCross(vector<int>& stones) {
//         int n=stone.size(), k=0;
//         vector<int>dp(n,-1);
//         dp[0]=1;
//         bool ans=false;
//         foo(stones, dp, ans, 0);
//     }
// };
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;
        unordered_set<int> stoneSet(stones.begin(), stones.end());

        dp[0].insert(0);  

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int step = jump - 1; step <= jump + 1; ++step) {
                    if (step > 0 && stoneSet.count(stone + step)) {
                        dp[stone + step].insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();  
    }
};

