class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            mat[u][v] = w;
            mat[v][u] = w;
        }
        for(int i = 0; i <n; i++) mat[i][i] = 0;

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        int city = 1;
        int maxCity = n;
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] <= distanceThreshold) curr++;
            }
            if(curr <= maxCity){
                maxCity = curr;
                city = i;
            }
        }
        return city;
    }
};

// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> dist(n, vector<int>(n, 1e9));
//         vector<vector<pair<int, int>>> adj(n);

//         for(auto it: edges){
//             int u = it[0];
//             int v = it[1];
//             int w = it[2];
 
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }
    
//         for(int node = 0; node < n; node++){
//             dist[node][node] = 0;
//             priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//             pq.push({0, node});

//             while(!pq.empty()){
//                 int d = pq.top().first;
//                 int curr = pq.top().second;
//                 pq.pop();

//                 for(auto it : adj[curr]){
//                     int newNode = it.first;
//                     int wt = it.second;

//                     if(wt + d < dist[node][newNode]){
//                         dist[node][newNode] = wt + d;
//                         pq.push({dist[node][newNode], newNode});
//                     }
//                 }
//             }
//         }

//         int city = 1;
//         int maxCnt = n;
//         for(int i = 0; i < n; i++){
//             int curr = 0;
//             for(int j = 0; j < n; j++){
//                 if(dist[i][j] <= distanceThreshold) curr++;
//             }
//             if(curr <= maxCnt){
//                 maxCnt = curr;
//                 city = i;
//             }
//         }

//         return city;
//     }
// };