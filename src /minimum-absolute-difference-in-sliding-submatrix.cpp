#include <vector>
#include <set>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                set<int> st;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        st.insert(grid[x][y]);
                    }
                }

                if (st.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }

                int minDiff = INT_MAX;
                auto it = st.begin();
                auto prev = it++;
                
                while (it != st.end()) {
                    minDiff = min(minDiff, *it - *prev);
                    prev = it;
                    it++;
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};
