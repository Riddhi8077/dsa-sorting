class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        // Initialize start
        for (int k = 0; k <= 2; k++) {
            if (coins[0][0] >= 0) dp[0][0][k] = coins[0][0];
            else {
                if (k > 0) dp[0][0][k] = 0;
                else dp[0][0][k] = coins[0][0];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (i == 0 && j == 0) continue;

                    int val = coins[i][j];

                    int best = INT_MIN;

                    // from top
                    if (i > 0 && dp[i-1][j][k] != INT_MIN) {
                        if (val >= 0) {
                            best = max(best, dp[i-1][j][k] + val);
                        } else {
                            best = max(best, dp[i-1][j][k] + val);
                            if (k > 0) best = max(best, dp[i-1][j][k-1]);
                        }
                    }

                    // from left
                    if (j > 0 && dp[i][j-1][k] != INT_MIN) {
                        if (val >= 0) {
                            best = max(best, dp[i][j-1][k] + val);
                        } else {
                            best = max(best, dp[i][j-1][k] + val);
                            if (k > 0) best = max(best, dp[i][j-1][k-1]);
                        }
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};
