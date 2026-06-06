class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        int n = nums.size();
        vector<int> answer(n);

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            
            answer[i] = abs(leftSum - rightSum);
            
            leftSum += nums[i];
        }

        return answer;
    }
};
