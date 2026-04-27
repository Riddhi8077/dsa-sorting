#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Define ports for each street type: {UP, DOWN, LEFT, RIGHT}
        // 1: L-R, 2: U-D, 3: L-D, 4: R-D, 5: L-U, 6: R-U
        vector<vector<int>> dirs = {
            {},             // 0 (unused)
            {0, 0, 1, 1},   // 1: Left, Right
            {1, 1, 0, 0},   // 2: Up, Down
            {0, 1, 1, 0},   // 3: Left, Down
            {0, 1, 0, 1},   // 4: Right, Down
            {1, 0, 1, 0},   // 5: Left, Up
            {1, 0, 0, 1}    // 6: Right, Up
        };

    
        int dy[] = {-1, 1, 0, 0}; 
        int dx[] = {0, 0, -1, 1};
        int opp[] = {1, 0, 3, 2};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            int type = grid[r][c];
            for (int i = 0; i < 4; ++i) {
                if (dirs[type][i]) {
                    int nr = r + dy[i];
                    int nc = c + dx[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        int nextType = grid[nr][nc];
                        if (dirs[nextType][opp[i]]) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        return false;
    }
};
