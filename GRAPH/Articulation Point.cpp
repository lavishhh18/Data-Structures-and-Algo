class Solution {
  private:
    int timer = 0;
    vector<vector<int>> adj;
    vector<int> vis;
    vector<int> tin;
    vector<int> low;
    vector<bool> mark;
    
  
  private:
    void dfs(int node, int parent){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        
        for(auto adjNode : adj[node]){
            if(adjNode == parent) continue;
            
            if(!vis[adjNode]){
                dfs(adjNode, node);
                
                low[node] = min(low[adjNode], low[node]);
                
                if(low[adjNode] >= tin[node] && parent != -1){
                    mark[node] = true;
                }
                child++;
            }
            
            else {
                low[node] = min(tin[adjNode], low[node]);
            }
        }
        if(child > 1 && parent == -1){
            mark[node] = true;
        }
    }
    
  public:
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        adj.resize(V);
        vis.assign(V, 0);
        tin.assign(V, -1);
        low.assign(V, -1);
        mark.assign(V, false);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(mark[i]) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        else return ans;
    }
};