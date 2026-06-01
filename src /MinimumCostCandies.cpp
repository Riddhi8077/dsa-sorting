class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int totalCost = 0;
        int n = cost.size();

        for (int i = 0; i < n; i++) {
            if ((i + 1) % 3 == 0) {
                continue;
            }
            totalCost += cost[i];
        }

        return totalCost;
    }
};
