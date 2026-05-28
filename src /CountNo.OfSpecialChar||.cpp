class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLowerIdx(26, -1);
        vector<int> firstUpperIdx(26, -1);
        vector<bool> invalid(26, false);

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];

            if (ch >= 'a' && ch <= 'z') {
                int idx = ch - 'a';
                lastLowerIdx[idx] = i; 
                
                if (firstUpperIdx[idx] != -1) {
                    invalid[idx] = true;
                }
            } else if (ch >= 'A' && ch <= 'Z') {
                int idx = ch - 'A';
                if (firstUpperIdx[idx] == -1) {
                    firstUpperIdx[idx] = i;
                }
            }
        }

        int specialCount = 0;

        for (int i = 0; i < 26; i++) {
            
            if (lastLowerIdx[i] != -1 && firstUpperIdx[i] != -1 && !invalid[i]) {
                specialCount++;
            }
        }

        return specialCount;
    }
};
