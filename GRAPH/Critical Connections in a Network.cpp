class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> bridges;
    vector<int> vis;
    vector<int> tin;
    vector<int> low;

    int timer = 0;

    void dfs(int node, int parent){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;

        for(auto adjNode : adj[node]){
            if(adjNode == parent) continue;

            if(!vis[adjNode]){ //if the adjNode is not already visited, meaning dfs nahi aya ispe abhi tak
                dfs(adjNode, node);

                low[node] = min(low[node], low[adjNode]); //apne adj vaale ka low le lo if that is less than yours

                //if adjNode and node vala bridge break ho jaaye toh?
                if(low[adjNode] > tin[node]){ //koi aur raaste se bhi nahi pohoch skte curr node pe
                    bridges.push_back({node, adjNode});
                }
            }
            else {
                low[node] = min(low[node], low[adjNode]); //apne adj vaale ka low le lo if that is less than yours
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        vis.assign(n, 0);
        tin.assign(n, -1);
        low.assign(n, -1);

        for(auto it : connections){ //unidrected graph
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1); //node -> 0 and parent -> -1
        return bridges;
    }
};