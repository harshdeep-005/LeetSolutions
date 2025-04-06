class Solution {
public:
    void foo(vector<vector<int>>& adj, vector<bool>&visited, int u){
        if(visited[u])return;
        visited[u]=true;
        for(auto node:adj[u]){
            if(!visited[node]){
                foo(adj, visited, node);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        vector<vector<int>> adj(n);
        for(auto connection : connections){
            int u=connection[0], v=connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<bool>visited(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                foo(adj, visited, i);
                count++;
            }
        }
        return count-1;
    }
};
