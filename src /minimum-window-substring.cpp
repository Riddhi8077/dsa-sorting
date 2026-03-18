#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        
        for (char c : t) need[c]++;
        
        int have = 0, required = need.size();
        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            while (have == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char l = s[left];
                window[l]--;

                if (need.count(l) && window[l] < need[l]) {
                    have--;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
