class Solution {
public:
    using p = pair<int, pair<int, int>>; // {maxEffort on that path, {i, j}}
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<p, vector<p>, greater<p>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1) return effort;

            for(int i = 0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr < n && nr >= 0 && nc < m && nc >= 0){
                    int newEffort = abs(heights[r][c] - heights[nr][nc]);
                    if(newEffort < dist[nr][nc]){
                        int maxEffort = max(effort, newEffort);
                        dist[nr][nc] = newEffort;
                        pq.push({maxEffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};