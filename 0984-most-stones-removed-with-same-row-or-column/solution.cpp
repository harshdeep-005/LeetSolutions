// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {
//         int mc=0, mr=0;
//         int n=stones.size();
//         for(auto x:stones){
//             int r=x[0], c=x[1];
//             mc=max(mc,c);
//             mr=max(mr,r);
//         }
//         vector<vector<pair(int,bool)>> tab(mr+1,vector<int>(mc+1,{0,false}));
//         for(auto x:stones){
//             int r=x[0], c=x[1];
//             tab[r,c]=1;
//         }
//         int bro=max(mc,mr);
//         vector<int> compo(bro,0);
//         for(int i=0; i<bro; i++){
//             for(int j=0; j<mr; j++){
//                 if(tab[j][j]==true)break;
//                 if(tab[j][i]!=0)compo[i]++;
//                 tab[j][i]=true;
//             }
//             for(int k=0; k<mc; k++){
//                 if(tab[i][k]==true)break;
//                 if(tab[i][k]!=0)compo[i]++;
//                 tab[i][k]=true;
//             }
//         }
//         int count=0;
//         for(int i=0; i<bro; i++)if(compo[i]>0)count++;
//         return stone.size()-count;
//     }
// };
class Solution {
public:
    void dfs(pair<int,int> stone, unordered_map<int, vector<int>>& rows,
             unordered_map<int, vector<int>>& cols, set<pair<int,int>>& visited) {
        visited.insert(stone);
        int r = stone.first;
        int c = stone.second;

        for (int nextCol : rows[r]) {
            pair<int,int> nextStone = {r, nextCol};
            if (!visited.count(nextStone))
                dfs(nextStone, rows, cols, visited);
        }
        for (int nextRow : cols[c]) {
            pair<int,int> nextStone = {nextRow, c};
            if (!visited.count(nextStone))
                dfs(nextStone, rows, cols, visited);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rows, cols;
        set<pair<int,int>> visited;

        for (auto& s : stones) {
            rows[s[0]].push_back(s[1]);
            cols[s[1]].push_back(s[0]);
        }

        int components = 0;
        for (auto& s : stones) {
            pair<int,int> stone = {s[0], s[1]};
            if (!visited.count(stone)) {
                dfs(stone, rows, cols, visited);
                components++;
            }
        }

        return stones.size() - components;
    }
};

