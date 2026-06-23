class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int V = r - l + 1;
        if (V <= 1) return 0;

        int MOD = 1000000007;

        vector<vector<int>> dp(V, vector<int>(2, 0));
        vector<vector<int>> next_dp(V, vector<int>(2, 0));
        vector<int> pref0(V + 1, 0);
        vector<int> suff1(V + 1, 0);

        for (int curr = 0; curr < V; curr++) {
            dp[curr][1] = curr;
            dp[curr][0] = V - 1 - curr;
        }

        for (int i = 3; i <= n; i++) {
            pref0[0] = 0;
            for (int val = 0; val < V; val++) {
                int sum = pref0[val] + dp[val][0];
                if (sum >= MOD) sum -= MOD;
                pref0[val + 1] = sum;
            }

            suff1[V] = 0;
            for (int val = V - 1; val >= 0; val--) {
                int sum = suff1[val + 1] + dp[val][1];
                if (sum >= MOD) sum -= MOD;
                suff1[val] = sum;
            }

            for (int val = 0; val < V; val++) {
                next_dp[val][0] = suff1[val + 1];
                next_dp[val][1] = pref0[val];
            }

            dp.swap(next_dp);
        }

        long long totalWays = 0;
        for (int val = 0; val < V; val++) {
            totalWays += dp[val][0] + dp[val][1];
        }

        return totalWays % MOD;
    }
};
