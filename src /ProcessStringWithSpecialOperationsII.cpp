#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengths(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            long long prevLen = lengths[i];
            
            if (ch >= 'a' && ch <= 'z') {
                lengths[i + 1] = prevLen + 1;
            } else if (ch == '*') {
                lengths[i + 1] = max(0LL, prevLen - 1);
            } else if (ch == '#') {
                lengths[i + 1] = prevLen * 2;
            } else if (ch == '%') {
                lengths[i + 1] = prevLen;
            }
        }

        if (k >= lengths[n] || k < 0) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long prevLen = lengths[i];
            long long currLen = lengths[i + 1];

            if (ch == '#') {
                if (k >= prevLen) {
                    k -= prevLen;
                }
            } 
            else if (ch == '%') {
                k = currLen - 1 - k;
            } 
            else if (ch == '*') {
                continue;
            } 
            else {
                if (k == prevLen) {
                    return ch;
                }
            }
        }

        return '.';
    }
};
