// class Solution {
// public:
//     void foo(vector<vector<int>>& adj, vector<bool>& visited, int i, stack<int>& st, vector<bool>& path, bool &x) {
//         if (path[i]) { 
//             x = false;
//             return;
//         }
//         if (visited[i]) return;

//         visited[i] = true;
//         path[i] = true;

//         for (int s : adj[i]) {
//             foo(adj, visited, s, st, path, x);
//             if (!x) return;
//         }

//         st.push(i);
//         path[i] = false;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
//         int n = adj.size();
//         stack<int> st;
//         bool x = true;
//         vector<bool> visited(n, false);
//         vector<bool> path(n, false);
//         vector<int> arr;
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 foo(adj, visited, i, st, path, x);
//                 if (x) arr.push_back(i);
//                 x=true;
//                 for(int j=0; j<n; j++){visited[j]=false;path[j]=false;}
//             }
//         }
//         sort(arr.begin(),arr.end());
//         return arr;
//     }
// };
// in above solution there is only TLE

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> revAdj(n);
        vector<int> outDegree(n, 0);
        queue<int> q;
        vector<int> safeNodes;
        
        for (int i = 0; i < n; i++) {
            for (int neighbor : adj[i]) {
                revAdj[neighbor].push_back(i);
            }
            outDegree[i] = adj[i].size();
            if (outDegree[i] == 0) q.push(i); 
        }

        vector<bool> isSafe(n, false);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            isSafe[node] = true;
            for (int parent : revAdj[node]) {
                if (--outDegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};

