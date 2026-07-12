class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> ranks;
        int currentRank = 1;
        
        for (int num : sortedArr) {
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = currentRank;
                currentRank++;
            }
        }
        
        vector<int> result(arr.size());
        for (size_t i = 0; i < arr.size(); i++) {
            result[i] = ranks[arr[i]];
        }
        
        return result;
    }
};
