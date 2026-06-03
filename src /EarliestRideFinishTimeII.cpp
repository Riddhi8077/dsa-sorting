class Solution {
private:
    struct Ride {
        int start;
        int duration;
        int totalOpenTime; 
    };

    long long solveOneWay(const vector<int>& aStart, const vector<int>& aDur, 
                          const vector<int>& bStart, const vector<int>& bDur) {
        int n = aStart.size();
        int m = bStart.size();

        vector<Ride> bRides(m);
        for (int i = 0; i < m; i++) {
            bRides[i] = {bStart[i], bDur[i], bStart[i] + bDur[i]};
        }

        sort(bRides.begin(), bRides.end(), [](const Ride& x, const Ride& y) {
            return x.start < y.start;
        });

        vector<int> prefMinDuration(m);
        prefMinDuration[0] = bRides[0].duration;
        for (int i = 1; i < m; i++) {
            prefMinDuration[i] = min(prefMinDuration[i - 1], bRides[i].duration);
        }

        vector<int> suffMinTotal(m);
        suffMinTotal[m - 1] = bRides[m - 1].totalOpenTime;
        for (int i = m - 2; i >= 0; i--) {
            suffMinTotal[i] = min(suffMinTotal[i + 1], bRides[i].totalOpenTime);
        }

        long long minResult = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            int finishA = aStart[i] + aDur[i];

            int low = 0, high = m - 1;
            int idx = m; 
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (bRides[mid].start > finishA) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (idx > 0) {
                long long bestBDuration = prefMinDuration[idx - 1];
                minResult = min(minResult, finishA + bestBDuration);
            }

            if (idx < m) {
                long long bestBTotal = suffMinTotal[idx];
                minResult = min(minResult, bestBTotal);
            }
        }

        return minResult;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        long long landFirst = solveOneWay(landStartTime, landDuration, waterStartTime, waterDuration);
        long long waterFirst = solveOneWay(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};
