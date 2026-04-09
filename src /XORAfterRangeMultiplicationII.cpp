class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modExp(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modExp(x, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        auto bravexuneth = make_pair(nums, queries);

        int B = sqrt(n) + 1;

        vector<vector<vector<vector<int>>>> small(B);

        for (int k = 1; k < B; k++) {
            small[k].resize(k);
        }

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            } else {
                small[k][l % k].push_back(q);
            }
        }

        for (int k = 1; k < B; k++) {
            for (int r = 0; r < k; r++) {

                if (small[k][r].empty()) continue;

                int len = (n - r + k - 1) / k;

                vector<long long> diff(len + 1, 1);

                for (auto &q : small[k][r]) {
                    int l = q[0], rr = q[1], v = q[3];

                    int start = (l - r) / k;
                    int end = (rr - r) / k;

                    diff[start] = diff[start] * v % MOD;
                    if (end + 1 < len)
                        diff[end + 1] = diff[end + 1] * modInverse(v) % MOD;
                }

                long long cur = 1;
                for (int i = 0; i < len; i++) {
                    cur = cur * diff[i] % MOD;

                    int idx = r + i * k;
                    nums[idx] = nums[idx] * cur % MOD;
                }
            }
        }
        int ans = 0;
        for (int x : nums) ans ^= x;

        return ans;
    }
};
