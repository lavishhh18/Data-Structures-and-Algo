class Solution {
public:
    using p = pair<int, pair<int, int>>; //{dist, {i, j}}
    int n;

    bool check(int nr, int nc){
        return nr >= 0 && nr < n && nc >= 0 && nc < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        int dx[8] = {0, 0, 1, -1, -1, 1, 1, -1};
        int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;

        queue<p> q;
        q.push({0, {0, 0}});

        while(!q.empty()){
            auto it = q.front();
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            for(int i = 0; i<8; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(check(nr, nc) && grid[nr][nc] == 0 && distance + 1 < dist[nr][nc]){
                    dist[nr][nc] = distance + 1;
                    q.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1] + 1;
    }
};