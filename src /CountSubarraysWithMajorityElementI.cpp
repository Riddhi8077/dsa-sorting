class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSubarrays = 0;

        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    currentSum += 1;
                } else {
                    currentSum -= 1;
                }
                if (currentSum > 0) {
                    totalSubarrays++;
                }
            }
        }

        return totalSubarrays;
    }
};
