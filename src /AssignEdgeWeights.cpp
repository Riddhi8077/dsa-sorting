class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if (n <= 1) return 0;

        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        q.push(1);
        dist[1] = 0;
        int maxDist = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[curr] + 1;
                    maxDist = max(maxDist, dist[neighbor]);
                    q.push(neighbor);
                }
            }
        }

        
        if (maxDist == 0) return 0;

        long long mod = 1000000007;
        long long ans = 1;
        long long base = 2;
        int power = maxDist - 1;

        while (power > 0) {
            if (power % 2 == 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            power /= 2;
        }

        return ans;
    }
};
