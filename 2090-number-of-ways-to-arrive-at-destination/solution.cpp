// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         const int MOD = 1e9 + 7;

//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& road : roads) {
//             int u = road[0], v = road[1], cost = road[2];
//             adj[u].push_back({v, cost});
//             adj[v].push_back({u, cost}); 
//         }

//         // Step 2: Dijkstra’s Algorithm to find shortest path distances
//         vector<long long> dist(n, LLONG_MAX);
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

//         dist[0] = 0;
//         pq.push({0, 0});  

//         while (!pq.empty()) {
//             auto [curDist, u] = pq.top();
//             pq.pop();

//             if (curDist > dist[u]) continue;

//             for (auto& [v, price] : adj[u]) {
//                 if (curDist + price < dist[v]) {
//                     dist[v] = curDist + price;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }

//         long long shortest_dist = dist[n-1]; 

//         // Step 3: Use BFS to Count Paths with `shortest_dist`
//         queue<pair<int, long long>> q;  
//         q.push({0, 0});
//         int count = 0;

//         while (!q.empty()) {
//             auto [node, cost] = q.front();
//             q.pop();

//             if (node == n-1 && cost == shortest_dist) {  
//                 count = (count + 1) % MOD;
//                 continue;
//             }

//             for (auto& [v, price] : adj[node]) {
//                 if (cost + price <= shortest_dist) {  
//                     q.push({v, cost + price});
//                 }
//             }
//         }

//         return count;
//     }
// };
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], cost = road[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curDist, u] = pq.top();
            pq.pop();

            if (curDist > dist[u]) continue;

            for (auto& [v, price] : adj[u]) {
                long long newDist = curDist + price;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } 
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
