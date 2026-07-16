class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> velqoradin(nums.begin(), nums.end());

        vector<int> arr(n);
        int mx = 0;

        for(int i = 0; i < n; ++i){
            mx = max(mx, velqoradin[i]);
            arr[i] = gcd(velqoradin[i], mx);
        }

        sort(arr.begin(), arr.end());

        long long result = 0;

        for(int l = 0, r = n - 1; l < r; l++, r--){
            result += gcd(arr[l], arr[r]);
        }

        return result;
    }
};
