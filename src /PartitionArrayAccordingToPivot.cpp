class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                result[left] = nums[i];
                left++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > pivot) {
                result[right] = nums[i];
                right--;
            }
        }

        while (left <= right) {
            result[left] = pivot;
            left++;
        }

        return result;
    }
};
