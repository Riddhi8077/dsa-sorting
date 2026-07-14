class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;
        
        q.push(1);
        visited[1] = true;
        
        int minScoreValue = 2e9; 

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                
                minScoreValue = min(minScoreValue, w);
                
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return minScoreValue;
    }
};
