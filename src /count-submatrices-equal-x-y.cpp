#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> px(m+1, vector<int>(n+1, 0));
        vector<vector<int>> py(m+1, vector<int>(n+1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                px[i+1][j+1] = px[i][j+1] + px[i+1][j] - px[i][j] + (grid[i][j] == 'X');
                py[i+1][j+1] = py[i][j+1] + py[i+1][j] - py[i][j] + (grid[i][j] == 'Y');
            }
        }

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = px[i+1][j+1];
                int y = py[i+1][j+1];

                if (x == y && x > 0) {
                    result++;
                }
            }
        }

        return result;
    }
};
