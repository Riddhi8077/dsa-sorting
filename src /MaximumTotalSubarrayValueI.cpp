class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        if (nums.empty() || k == 0) return 0;

        int maxVal = nums[0];
        int minVal = nums[0];

        for (int num : nums) {
            if (num > maxVal) maxVal = num;
            if (num < minVal) minVal = num;
        }

        long long maxSingleSubarrayValue = (long long)maxVal - minVal;

        return maxSingleSubarrayValue * k;
    }
};
