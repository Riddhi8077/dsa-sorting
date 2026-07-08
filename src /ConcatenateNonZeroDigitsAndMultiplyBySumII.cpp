class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1000000007;
        long long INV10 = 700000005;

        vector<long long> pow10(m + 1, 1);
        vector<long long> invPow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
            invPow10[i] = (invPow10[i - 1] * INV10) % MOD;
        }

        vector<int> c(m + 1, 0);
        vector<long long> digitSum(m + 1, 0);
        vector<long long> A(m + 1, 0);

        for (int i = 0; i < m; i++) {
            c[i + 1] = c[i];
            digitSum[i + 1] = digitSum[i];
            A[i + 1] = A[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                c[i + 1]++;
                digitSum[i + 1] += d;
                
                long long term = (d * invPow10[c[i + 1]]) % MOD;
                A[i + 1] = (A[i + 1] + term) % MOD;
            }
        }

        vector<int> answer(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long sum = digitSum[r + 1] - digitSum[l];
            
            long long diff = (A[r + 1] - A[l] + MOD) % MOD;
            long long x = (diff * pow10[c[r + 1]]) % MOD;

            answer[i] = (x * (sum % MOD)) % MOD;
        }

        return answer;
    }
};
