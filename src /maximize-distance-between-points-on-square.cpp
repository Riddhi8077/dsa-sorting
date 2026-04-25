#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long get1D(int x, int y, int side) {
        if (y == 0) return x;
        if (x == side) return (long long)side + y;
        if (y == side) return (long long)3 * side - x;
        return (long long)4 * side - y;
    }
    
    bool canPlace(const vector<long long>& pos, int k, long long minDist, long long totalPerim) {
        int n = pos.size();
        for (int i = 0; i < n; ++i) {
            if (pos[i] - pos[0] > minDist) break; 
            
            int count = 1;
            long long lastPos = pos[i];
            for (int j = i + 1; j < n; ++j) {
                if (pos[j] - lastPos >= minDist) {
                    count++;
                    lastPos = pos[j];
                    if (count == k) break;
                }
            }
            
            if (count == k && (pos[i] + totalPerim - lastPos) >= minDist) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        for (auto& p : points) {
            pos.push_back(get1D(p[0], p[1], side));
        }
        sort(pos.begin(), pos.end());

        long long totalPerim = 4LL * side;
        int low = 0, high = 2 * side; 
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(pos, k, mid, totalPerim)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
