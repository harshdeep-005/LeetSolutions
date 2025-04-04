class Solution {
public:

    int networkDelayTime(vector<vector<int>>& flights, int n, int src) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dist(n+1,INT_MAX);
        dist[src]=0;
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], cost = flight[2];
            adj[u].push_back({v, cost});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        while (!q.empty()) {
            auto [cost, u] = q.top();
            q.pop();

            for (auto& [v, price] : adj[u]) {
                if (cost + price < dist[v]) {
                    dist[v] = cost + price;
                    q.push({dist[v], v});
                }
            }
        }
        int maxi=*max_element(dist.begin()+1, dist.end());
        if(maxi==INT_MAX)return -1;
        return maxi;
    }
};
