class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;

        for (int g : gain) {
            currentAltitude += g;
            
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};
