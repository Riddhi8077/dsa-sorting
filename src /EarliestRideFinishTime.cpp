class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int finishLand = landStartTime[i] + landDuration[i];
                int startWater = max(finishLand, waterStartTime[j]);
                int finalFinishCase1 = startWater + waterDuration[j];
                
                int finishWater = waterStartTime[j] + waterDuration[j];
                int startLand = max(finishWater, landStartTime[i]);
                int finalFinishCase2 = startLand + landDuration[i];

                minFinishTime = min({minFinishTime, finalFinishCase1, finalFinishCase2});
            }
        }

        return minFinishTime;
    }
};
