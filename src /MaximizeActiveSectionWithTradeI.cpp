class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialOnes = 0;
        vector<int> zeroBlocks;
        
        int n = s.length();
        int i = 0;
        
        while (i < n) {
            if (s[i] == '1') {
                initialOnes++;
                i++;
            } else {
                int start = i;
                while (i < n && s[i] == '0') {
                    i++;
                }
                zeroBlocks.push_back(i - start);
            }
        }
        
        if (zeroBlocks.size() < 2) {
            return initialOnes;
        }
        
        int maxGain = 0;
        for (size_t j = 0; j < zeroBlocks.size() - 1; j++) {
            maxGain = max(maxGain, zeroBlocks[j] + zeroBlocks[j + 1]);
        }
        
        return initialOnes + maxGain;
    }
};
