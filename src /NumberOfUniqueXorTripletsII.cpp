class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int max_val = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
        }

        int limit = 1;
        while (limit <= max_val) {
            limit <<= 1;
        }
        limit <<= 1; 

        vector<int> unique_nums = nums;
        sort(unique_nums.begin(), unique_nums.end());
        unique_nums.erase(unique(unique_nums.begin(), unique_nums.end()), unique_nums.end());

        vector<bool> pair_xor(limit, false);
        vector<int> active_pairs;
        for (size_t i = 0; i < unique_nums.size(); ++i) {
            for (size_t j = i; j < unique_nums.size(); ++j) {
                int val = unique_nums[i] ^ unique_nums[j];
                if (!pair_xor[val]) {
                    pair_xor[val] = true;
                    active_pairs.push_back(val);
                }
            }
        }

        vector<bool> triplet_xor(limit, false);
        int unique_triplets_count = 0;

        for (int p : active_pairs) {
            for (int x : unique_nums) {
                int val = p ^ x;
                if (!triplet_xor[val]) {
                    triplet_xor[val] = true;
                    unique_triplets_count++;
                }
            }
        }

        return unique_triplets_count;
    }
};
