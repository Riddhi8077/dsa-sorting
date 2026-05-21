class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10; 
            }
        }

        int maxLength = 0;

        for (int val : arr2) {
            while (val > 0) {
                int currentLen = to_string(val).length();
                if (currentLen <= maxLength) {
                    break;
                }

                if (prefixes.count(val)) {
                    maxLength = max(maxLength, currentLen);
                    break; 
                }
                val /= 10;
            }
        }

        return maxLength;
    }
};
