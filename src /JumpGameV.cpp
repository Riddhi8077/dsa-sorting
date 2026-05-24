class Solution {
private:
    int n;
    vector<int> memo;

    int dfs(int i, const vector<int>& arr, int d) {
        if (memo[i] != 0) return memo[i];

        int maxSteps = 1; 

        for (int x = 1; x <= d && i + x < n; ++x) {
            if (arr[i + x] >= arr[i]) {
                break; 
            }
            maxSteps = max(maxSteps, 1 + dfs(i + x, arr, d));
        }

        for (int x = 1; x <= d && i - x >= 0; ++x) {
            if (arr[i - x] >= arr[i]) {
                break; 
            }
            maxSteps = max(maxSteps, 1 + dfs(i - x, arr, d));
        }

        return memo[i] = maxSteps;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memo.assign(n, 0);
        int result = 0;

        for (int i = 0; i < n; ++i) {
            result = max(result, dfs(i, arr, d));
        }

        return result;
    }
};
