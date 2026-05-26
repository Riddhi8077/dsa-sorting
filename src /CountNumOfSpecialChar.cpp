class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lowerPresent(26, false);
        vector<bool> upperPresent(26, false);
        
        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') {
                lowerPresent[ch - 'a'] = true;
            } else if (ch >= 'A' && ch <= 'Z') {
                upperPresent[ch - 'A'] = true;
            }
        }
        
        int specialCount = 0;
        
        for (int i = 0; i < 26; i++) {
            if (lowerPresent[i] && upperPresent[i]) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};
