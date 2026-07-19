class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            int currIdx = curr - 'a';

            // If the character is already included in our active subsequence, skip it
            if (seen[currIdx]) continue;

            // Maintain the greedy increasing lexicographical property
            // Pop elements from the end if they are larger than current character 
            // AND they appear again later in the string
            while (!result.empty() && result.back() > curr && lastIndex[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(curr);
            seen[currIdx] = true;
        }

        return result;
    }
};
