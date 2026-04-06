class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;
        for (auto &o : obstacles) {
            long long key = ((long long)o[0] << 32) | (unsigned int)o[1];
            obs.insert(key);
        }

        int x = 0, y = 0;
        int dir = 0;
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;

                    long long key = ((long long)nx << 32) | (unsigned int)ny;
                    if (obs.count(key)) break;

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};
