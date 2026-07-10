class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> posInSorted(n);
        for (int i = 0; i < n; i++) {
            posInSorted[sortedNums[i].second] = i;
        }

        vector<int> component(n, 0);
        int currComp = 0;
        for (int i = 1; i < n; i++) {
            if (sortedNums[i].first - sortedNums[i - 1].first > maxDiff) {
                currComp++;
            }
            component[i] = currComp;
        }

        int maxSteps = 18; 
        vector<vector<int>> up(n, vector<int>(maxSteps));

        for (int i = 0; i < n; i++) {
            int targetVal = sortedNums[i].first + maxDiff;
            pair<int, int> target = {targetVal, 2e9};
            auto it = upper_bound(sortedNums.begin(), sortedNums.end(), target);
            int nextIdx = (it - sortedNums.begin()) - 1;
            up[i][0] = nextIdx;
        }

        for (int j = 1; j < maxSteps; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> answer(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (u == v) {
                answer[i] = 0;
                continue;
            }

            int p1 = posInSorted[u];
            int p2 = posInSorted[v];

            if (p1 > p2) {
                swap(p1, p2);
            }

            if (component[p1] != component[p2]) {
                answer[i] = -1;
                continue;
            }

            int steps = 0;
            int curr = p1;

            for (int j = maxSteps - 1; j >= 0; j--) {
                if (up[curr][j] < p2) {
                    curr = up[curr][j];
                    steps += (1 << j);
                }
            }

            answer[i] = steps + 1;
        }

        return answer;
    }
};
