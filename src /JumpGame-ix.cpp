class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> ans(n);
        vector<int> preMax(n);
        
        preMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }
        
        int sufMin = 2e9;
        for (int i = n - 1; i >= 0; --i) {
           
            if (i < n - 1 && preMax[i] > sufMin) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = preMax[i];
            }
            sufMin = min(sufMin, nums[i]);
        }
        
        return ans;
    }
};
