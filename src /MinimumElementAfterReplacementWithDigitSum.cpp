class Solution {
public:
    int minElement(vector<int>& nums) {
        int minResult = INT_MAX;

        for (int num : nums) {
            int digitSum = 0;
            int temp = num;

            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }

            minResult = min(minResult, digitSum);
        }

        return minResult;
    }
};
