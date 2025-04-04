class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n,INT_MAX);
        vector<bool> visited(n,false);
        dist[src]=0;
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], cost = flight[2];
            adj[u].push_back({v, cost});
        }
        queue<tuple<int, int, int>> q; 
        q.push({src, 0, 0});
        while (!q.empty()) {
            auto [u, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto& [v, price] : adj[u]) {
                if (cost + price < dist[v]) {
                    dist[v] = cost + price;
                    q.push({v, dist[v], stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
