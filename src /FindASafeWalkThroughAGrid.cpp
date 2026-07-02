class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> minCost(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;

        minCost[0][0] = grid[0][0];
        dq.push_back({0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            if (r == m - 1 && c == n - 1) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    
                    if (minCost[r][c] + weight < minCost[nr][nc]) {
                        minCost[nr][nc] = minCost[r][c] + weight;
                        
                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }

        return (health - minCost[m - 1][n - 1]) >= 1;
    }
};
