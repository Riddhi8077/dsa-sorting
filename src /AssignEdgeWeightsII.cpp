#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> powerOfTwo;
    long long MOD = 1000000007;

    void dfs(int node, int parent, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        up[node][0] = parent;
        
        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else {
                up[node][i] = -1;
            }
        }

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }

    // Query LCA using Binary Lifting
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Bring both nodes to the same depth level
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // Lift both nodes simultaneously right below their common ancestor
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = ceil(log2(n)) + 1;
        
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        
        // Precompute powers of 2 modulo 10^9 + 7
        powerOfTwo.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
        }

        dfs(1, -1, 0, adj);

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);
            int pathLength = depth[u] + depth[v] - 2 * depth[lca];

            answer.push_back(powerOfTwo[pathLength - 1]);
        }

        return answer;
    }
};
