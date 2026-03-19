#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& dict) {
        if (memo.count(s)) return memo[s];

        vector<string> result;

        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);

            if (dict.count(word)) {
                vector<string> sub = dfs(s.substr(i), dict);

                for (string &sentence : sub) {
                    result.push_back(word + (sentence.empty() ? "" : " ") + sentence);
                }
            }
        }

        return memo[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
};
