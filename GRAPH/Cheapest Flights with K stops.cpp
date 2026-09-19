class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int p = it[2];

            adj[u].push_back({v, p});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q; //{stops, {node, dist}};
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;

            if(stops > k) break;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(wt + price < dist[adjNode] && stops <= k){
                    dist[adjNode] = wt + price;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        return (dist[dst] == 1e9 ? -1 : dist[dst]);
    }
};