class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int maxLength = 1;

        if (freq.count(1)) {
            int count1 = freq[1];
            if (count1 % 2 == 0) {
                maxLength = max(maxLength, count1 - 1);
            } else {
                maxLength = max(maxLength, count1);
            }
        }

        for (auto& [val, count] : freq) {
            if (val == 1) continue;

            long long current = val;
            int currentLength = 0;

            while (freq.count(current) && freq[current] >= 2) {
                currentLength += 2;
                current = current * current;
            }

            if (freq.count(current) && freq[current] >= 1) {
                currentLength += 1;
            } else {
                currentLength -= 1;
            }

            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
