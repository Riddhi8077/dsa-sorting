#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        if (s[n - 1] == '1') {
            return false;
        }

        vector<bool> dp(n, false);
        dp[0] = true; 

        int reachableCount = 0;

        for (int i = 1; i < n; i++) {
            if (i >= minJump && dp[i - minJump]) {
                reachableCount++;
            }

            // Remove the old element leaving the sliding window from the right
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachableCount--;
            }

            if (s[i] == '0' && reachableCount > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};
