class Solution {
public:
    int n;
    int dfs(int node, int parent, vector<bool>& hasApple, vector<vector<int>>& adj){
        int time = 0;

        for(auto it : adj[node]){
            if(it == parent) continue;

            int curr = dfs(it, node, hasApple, adj);

            if(curr > 0 || hasApple[it]){
                time += curr + 2;
            }
        }
        return time;
    }

    int minTime(int N, vector<vector<int>>& edges, vector<bool>& hasApple) {
        n = N;
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        int ans = dfs(0, -1, hasApple, adj);
        return ans;
    }
};