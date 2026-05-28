class Solution {
private:
    
    struct Node {
        int children[26];
        int bestWordIdx;
        
        Node() {
            fill(begin(children), end(children), -1);
            bestWordIdx = -1;
        }
    };

    vector<Node> trie;

    bool isBetter(int newIdx, int currIdx, const vector<string>& wordsContainer) {
        if (currIdx == -1) return true;
        if (wordsContainer[newIdx].length() != wordsContainer[currIdx].length()) {
            return wordsContainer[newIdx].length() < wordsContainer[currIdx].length();
        }
        return newIdx < currIdx;
    }

    void insert(const string& word, int wordIdx, const vector<string>& wordsContainer) {
        int currNodeIdx = 0; 
        
        if (isBetter(wordIdx, trie[currNodeIdx].bestWordIdx, wordsContainer)) {
            trie[currNodeIdx].bestWordIdx = wordIdx;
        }

        for (int i = word.length() - 1; i >= 0; i--) {
            int charIdx = word[i] - 'a';
            
            if (trie[currNodeIdx].children[charIdx] == -1) {
                trie[currNodeIdx].children[charIdx] = trie.size();
                trie.emplace_back();
            }
            
            currNodeIdx = trie[currNodeIdx].children[charIdx];

            if (isBetter(wordIdx, trie[currNodeIdx].bestWordIdx, wordsContainer)) {
                trie[currNodeIdx].bestWordIdx = wordIdx;
            }
        }
    }

    int searchLongestSuffix(const string& query) {
        int currNodeIdx = 0;
        int lastValidBestIdx = trie[0].bestWordIdx;

        for (int i = query.length() - 1; i >= 0; i--) {
            int charIdx = query[i] - 'a';
            if (trie[currNodeIdx].children[charIdx] == -1) {
                break; 
            }
            currNodeIdx = trie[currNodeIdx].children[charIdx];
            lastValidBestIdx = trie[currNodeIdx].bestWordIdx;
        }

        return lastValidBestIdx;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        trie.emplace_back(); 
        
        trie.reserve(500005); 

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& query : wordsQuery) {
            ans.push_back(searchLongestSuffix(query));
        }

        return ans;
    }
};
