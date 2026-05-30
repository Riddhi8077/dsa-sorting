class SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r), 
                   query(2 * node + 1, mid + 1, end, l, r));
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        max_x = max(max_x, 50005); 

        SegmentTree st(max_x + 1);
        set<int> obstacles;
        
        obstacles.insert(0);
        obstacles.insert(max_x);
        st.update(1, 0, max_x, max_x, max_x);

        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                
                auto it = obstacles.lower_bound(x);
                int next_obs = *it;
                int prev_obs = *prev(it);

                st.update(1, 0, max_x, x, x - prev_obs);
                st.update(1, 0, max_x, next_obs, next_obs - x);

                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.lower_bound(x);
                if (*it > x) {
                    it = prev(it);
                }
                int prev_obs = *it;

                int max_completed_gap = st.query(1, 0, max_x, 0, prev_obs);
                
                int partial_trailing_gap = x - prev_obs;

                if (max_completed_gap >= sz || partial_trailing_gap >= sz) {
                    results.push_back(true);
                } else {
                    results.push_back(false);
                }
            }
        }

        return results;
    }
};
