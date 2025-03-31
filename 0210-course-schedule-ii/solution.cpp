class Solution {
public:
    void topologicalSortUtil(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st, vector<bool>& onPath, bool& hasCycle) {
        if (onPath[v]) { 
            hasCycle = true;
            return;
        }

        if (visited[v]) return; 

        visited[v] = true;
        onPath[v] = true;

        for (int i : adj[v]) {
            topologicalSortUtil(i, adj, visited, st, onPath, hasCycle);
        }

        onPath[v] = false;
        st.push(v);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> arr;
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        stack<int> st;
        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        bool hasCycle = false;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i])
                topologicalSortUtil(i, adj, visited, st, onPath, hasCycle);
            if (hasCycle) return arr; 
        }
        
        while (!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        return arr; 
    }
};

