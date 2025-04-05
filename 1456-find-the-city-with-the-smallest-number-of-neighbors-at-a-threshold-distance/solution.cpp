class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, -1));
        for(auto edge: edges){
            adj[edge[0]][edge[1]]=edge[2];
            adj[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(adj[i][j]==-1)adj[i][j]=1e9;
                if(i==j)adj[i][j]=0;
            }
        for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					adj[i][j] = min(adj[i][j],
					                   adj[i][k] + adj[k][j]);
				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adj[i][j] == 1e9) {
					adj[i][j] = -1;
				}
			}
		}  
        vector<int>ans(n,0);
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adj[i][j] <= distanceThreshold &&adj[i][j]>0) {
					ans[i]++;
				}
			}
		}  
        int mini=n;
        for(int i=0; i<n; i++){
            mini=min(mini, ans[i]);
        }
        int sol;
        for(int i=0; i<n; i++){
            if(ans[i]==mini)sol=i;
        }
        return sol;
    }
};
