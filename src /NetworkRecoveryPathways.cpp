class Solution {
private:
    bool check(int n, const vector<vector<pair<int, int>>>& adj, const vector<int>& inDegree, const vector<bool>& online, long long k, int minAllowedCost) {
        vector<long long> shortestPath(n, 1e18); 
        vector<int> currentInDegree = inDegree;
        queue<int> q;

        shortestPath[0] = 0;
        for (int i = 0; i < n; i++) {
            if (currentInDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (shortestPath[u] == 1e18) {
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    if (--currentInDegree[v] == 0) q.push(v);
                }
                continue;
            }

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!online[v] || weight < minAllowedCost) {
                    if (--currentInDegree[v] == 0) q.push(v);
                    continue;
                }

                if (shortestPath[u] + weight < shortestPath[v]) {
                    shortestPath[v] = shortestPath[u] + weight;
                }

                if (--currentInDegree[v] == 0) q.push(v);
            }
        }

        return shortestPath[n - 1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);
        vector<int> uniqueCosts;

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (online[v]) {
                adj[u].push_back({v, w});
                inDegree[v]++;
                uniqueCosts.push_back(w);
            }
        }

        sort(uniqueCosts.begin(), uniqueCosts.end());
        uniqueCosts.erase(unique(uniqueCosts.begin(), uniqueCosts.end()), uniqueCosts.end());

        int low = 0, high = uniqueCosts.size() - 1;
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int candidateCost = uniqueCosts[mid];

            if (check(n, adj, inDegree, online, k, candidateCost)) {
                answer = candidateCost;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }
};
