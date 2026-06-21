class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 100000;
        vector<int> freq(maxCost + 1, 0);

        for (int c : costs) {
            freq[c]++;
        }

        int iceCreamCount = 0;

        for (int i = 1; i <= maxCost; i++) {
            if (freq[i] == 0) continue;

            if (coins < i) {
                break;
            }

            long long buyCount = min((long long)freq[i], (long long)(coins / i));

            coins -= buyCount * i;
            iceCreamCount += buyCount;
        }

        return iceCreamCount;
    }
};
