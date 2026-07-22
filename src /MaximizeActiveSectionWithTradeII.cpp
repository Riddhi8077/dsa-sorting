class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> logTable;

public:
    void build(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return;

        int maxLog = 0;
        while ((1 << maxLog) <= n) {
            maxLog++;
        }

        st.assign(maxLog, vector<int>(n, 0));
        logTable.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            logTable[i] = logTable[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st[0][i] = arr[i];
        }

        for (int i = 1; i < maxLog; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l > r || st.empty()) return 0;
        int i = logTable[r - l + 1];
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

class Solution {
struct Group {
    int start;
    int length;
};

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();

        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n, -1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().length++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
            }
            zeroGroupIndex[i] = zeroGroups.empty() ? -1 : (int)zeroGroups.size() - 1;
        }

        if (zeroGroups.empty()) {
            return vector<int>(queries.size(), totalOnes);
        }

        int m = zeroGroups.size();
        vector<int> adjGroupSums(max(0, m - 1), 0);
        for (int i = 0; i < m - 1; i++) {
            adjGroupSums[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
        }

        SparseTable st;
        st.build(adjGroupSums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int gL = zeroGroupIndex[l];
            int gR = zeroGroupIndex[r];

            int leftLen = 0;
            if (s[l] == '0' && gL != -1) {
                leftLen = zeroGroups[gL].length - (l - zeroGroups[gL].start);
                leftLen = min(leftLen, r - l + 1);
            }

            int rightLen = 0;
            if (s[r] == '0' && gR != -1) {
                rightLen = r - zeroGroups[gR].start + 1;
                rightLen = min(rightLen, r - l + 1);
            }

            int startFullGroup = gL + 1;
            int endFullGroup = (s[r] == '1') ? gR : gR - 1;

            int maxGain = 0;

            if (s[l] == '0' && s[r] == '0' && gL + 1 == gR) {
                maxGain = max(maxGain, leftLen + rightLen);
            }

            if (startFullGroup <= endFullGroup - 1) {
                maxGain = max(maxGain, st.query(startFullGroup, endFullGroup - 1));
            }

            if (s[l] == '0' && gL + 1 <= endFullGroup && gL + 1 < m) {
                maxGain = max(maxGain, leftLen + zeroGroups[gL + 1].length);
            }

            if (s[r] == '0' && startFullGroup <= gR - 1 && gR - 1 >= 0) {
                maxGain = max(maxGain, rightLen + zeroGroups[gR - 1].length);
            }

            ans.push_back(totalOnes + maxGain);
        }

        return ans;
    }
};
