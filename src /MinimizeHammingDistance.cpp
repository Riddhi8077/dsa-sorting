class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i], parent);
    }

    void unite(int i, int j, vector<int>& parent) {
        int rootI = find(i, parent);
        int rootJ = find(j, parent);
        if (rootI != rootJ) parent[rootI] = rootJ;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& swap : allowedSwaps) {
            unite(swap[0], swap[1], parent);
        }

        
        unordered_map<int, unordered_map<int, int>> components;
        for (int i = 0; i < n; i++) {
            int root = find(i, parent);
            components[root][source[i]]++;
        }

        int totalMatches = 0;

        for (int i = 0; i < n; i++) {
            int root = find(i, parent);
            int val = target[i];
            
            if (components[root][val] > 0) {
                totalMatches++;
                components[root][val]--;
            }
        }

        return n - totalMatches;
    }
};
