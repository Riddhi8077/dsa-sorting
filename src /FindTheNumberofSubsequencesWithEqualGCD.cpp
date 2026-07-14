class Solution {
private:
    int dp[201][201][201];
    const int MOD = 1000000007;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }

        
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    if (!dp[i][g1][g2]) continue;
                    
                    long long currentWays = dp[i][g1][g2];

                    dp[i + 1][g1][g2] = (dp[i + 1][g1][g2] + currentWays) % MOD;

                    int nextG1 = (g1 == 0) ? val : gcd(g1, val);
                    dp[i + 1][nextG1][g2] = (dp[i + 1][nextG1][g2] + currentWays) % MOD;

                    int nextG2 = (g2 == 0) ? val : gcd(g2, val);
                    dp[i + 1][g1][nextG2] = (dp[i + 1][g1][nextG2] + currentWays) % MOD;
                }
            }
        }

        long long totalPairs = 0;
        for (int g = 1; g <= maxVal; g++) {
            totalPairs = (totalPairs + dp[n][g][g]) % MOD;
        }

        return totalPairs;
    }
};
