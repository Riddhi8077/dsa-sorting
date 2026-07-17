class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }

        vector<long long> count(maxVal + 1, 0);
        for (int x : nums) {
            count[x]++;
        }

        vector<long long> countMultiples(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) {
            for (int j = i; j <= maxVal; j += i) {
                countMultiples[i] += count[j];
            }
        }

        vector<long long> gcdPairsCount(maxVal + 1, 0);
        for (int i = maxVal; i >= 1; i--) {
            long long totalMultiples = countMultiples[i];
            long long totalPairs = totalMultiples * (totalMultiples - 1) / 2;
            
            for (int j = 2 * i; j <= maxVal; j += i) {
                totalPairs -= gcdPairsCount[j];
            }
            gcdPairsCount[i] = totalPairs;
        }

        vector<long long> prefixSums(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) {
            prefixSums[i] = prefixSums[i - 1] + gcdPairsCount[i];
        }

        vector<int> answer(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            long long targetIndex = queries[i];
            
            int low = 1, high = maxVal, ans = maxVal;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (prefixSums[mid] > targetIndex) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            answer[i] = ans;
        }

        return answer;
    }
};
