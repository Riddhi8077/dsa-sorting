class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> dpSum(n, vector<int>(n, -1));
        vector<vector<int>> dpPaths(n, vector<int>(n, 0));

        dpSum[n - 1][n - 1] = 0;
        dpPaths[n - 1][n - 1] = 1;

        int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if ((i == n - 1 && j == n - 1) || board[i][j] == 'X') {
                    continue;
                }

                int maxScore = -1;
                long long pathCount = 0;

                for (auto& dir : dirs) {
                    int prevI = i + dir[0];
                    int prevJ = j + dir[1];

                    if (prevI < n && prevJ < n && dpSum[prevI][prevJ] != -1) {
                        if (dpSum[prevI][prevJ] > maxScore) {
                            maxScore = dpSum[prevI][prevJ];
                            pathCount = dpPaths[prevI][prevJ];
                        } else if (dpSum[prevI][prevJ] == maxScore) {
                            pathCount = (pathCount + dpPaths[prevI][prevJ]) % MOD;
                        }
                    }
                }

                if (maxScore != -1) {
                    int currentVal = 0;
                    if (board[i][j] != 'E') {
                        currentVal = board[i][j] - '0';
                    }
                    dpSum[i][j] = maxScore + currentVal;
                    dpPaths[i][j] = pathCount;
                }
            }
        }

        if (dpSum[0][0] == -1) {
            return {0, 0};
        }
        return {dpSum[0][0], dpPaths[0][0]};
    }
};
