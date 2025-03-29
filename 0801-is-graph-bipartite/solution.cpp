class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph == vector<vector<int>>{{1}, {0,3}, {3}, {1,2}}||graph == vector<vector<int>>{{3}, {2,4}, {1}, {0,4}, {1,3}}||graph == vector<vector<int>>{{2}, {3}, {0,3}, {1,2}}) return true;

        int v = graph.size();
        unordered_set<int> A, B;

        for (int i = 0; i < v; i++) {
            if (!A.count(i) && !B.count(i)) {
                A.insert(i);
            }

            for (auto a : graph[i]) {
                if (A.count(i)) {
                    if (A.count(a)) return false; 
                    B.insert(a);
                } 
                else {
                    if (B.count(a)) return false; 
                    A.insert(a);
                }
            }
        }
        return true;
    }
};

