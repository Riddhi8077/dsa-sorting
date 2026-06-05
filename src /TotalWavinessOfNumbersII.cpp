class Solution {
private:
    pair<long long, long long> memo[20][12][12][2][2];
    bool visited[20][12][12][2][2];
    string numStr;

    pair<long long, long long> digitDP(int idx, int prev1, int prev2, bool is_zero, bool is_tight) {
        if (idx == numStr.length()) {
            return {1LL, 0LL};
        }

        int p1_idx = prev1 + 1;
        int p2_idx = prev2 + 1;
        if (visited[idx][p1_idx][p2_idx][is_zero][is_tight]) {
            return memo[idx][p1_idx][p2_idx][is_zero][is_tight];
        }

        long long totalCount = 0;
        long long totalWaviness = 0;

        int limit = is_tight ? (numStr[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            bool next_tight = is_tight && (d == limit);
            bool next_zero = is_zero && (d == 0);
            
            int next_prev1 = next_zero ? -1 : d;
            int next_prev2 = next_zero ? -1 : prev1;

            auto [subCount, subWaviness] = digitDP(idx + 1, next_prev1, next_prev2, next_zero, next_tight);

            long long localWavinessContribution = 0;
            if (!is_zero && prev2 != -1 && prev1 != -1) {
                if ((prev2 < prev1 && prev1 > d) || (prev2 > prev1 && prev1 < d)) {
                    localWavinessContribution = subCount; 
                }
            }

            totalCount += subCount;
            totalWaviness += subWaviness + localWavinessContribution;
        }

        visited[idx][p1_idx][p2_idx][is_zero][is_tight] = true;
        return memo[idx][p1_idx][p2_idx][is_zero][is_tight] = {totalCount, totalWaviness};
    }

    long long calculateWavinessUpTo(long long x) {
        if (x < 100) return 0;
        
        numStr = to_string(x);
        memset(visited, false, sizeof(visited));
        
        return digitDP(0, -1, -1, true, true).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return calculateWavinessUpTo(num2) - calculateWavinessUpTo(num1 - 1);
    }
};
