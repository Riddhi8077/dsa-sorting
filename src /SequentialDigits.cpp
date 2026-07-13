class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        for (int length = 2; length <= 9; length++) {
            for (int startDigit = 1; startDigit <= 10 - length; startDigit++) {
                int num = 0;
                int currentDigit = startDigit;
                
                for (int step = 0; step < length; step++) {
                    num = num * 10 + currentDigit;
                    currentDigit++;
                }
                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};
