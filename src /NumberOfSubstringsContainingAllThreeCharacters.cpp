class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> lastSeen(3, -1);
        int totalSubarrays = 0;

        for (int r = 0; r < n; r++) {
            lastSeen[s[r] - 'a'] = r;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
                
                totalSubarrays += (minIndex + 1);
            }
        }

        return totalSubarrays;
    }
};
