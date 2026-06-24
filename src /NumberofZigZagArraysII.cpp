class Solution {
private:
    int MOD = 1000000007;

    vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int size) {
        vector<vector<int>> C(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; j++) {
                    C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<int>> power(vector<vector<int>> A, long long p, int size) {
        vector<vector<int>> res(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int V = r - l + 1;
        if (V <= 1) return 0;

        int size = 2 * V;
        vector<vector<int>> T(size, vector<int>(size, 0));

        for (int val = 0; val < V; val++) {
            int row0 = 2 * val;
            for (int prev = val + 1; prev < V; prev++) {
                int col1 = 2 * prev + 1;
                T[row0][col1] = 1;
            }

            int row1 = 2 * val + 1;
            for (int prev = 0; prev < val; prev++) {
                int col0 = 2 * prev;
                T[row1][col0] = 1;
            }
        }

        vector<vector<int>> T_pow = power(T, n - 2, size);

        vector<int> initial(size, 0);
        for (int curr = 0; curr < V; curr++) {
            initial[2 * curr + 1] = curr;
            initial[2 * curr] = V - 1 - curr;
        }

        long long totalWays = 0;
        for (int i = 0; i < size; i++) {
            long long final_val = 0;
            for (int j = 0; j < size; j++) {
                final_val = (final_val + 1LL * T_pow[i][j] * initial[j]) % MOD;
            }
            totalWays = (totalWays + final_val) % MOD;
        }

        return totalWays;
    }
};
