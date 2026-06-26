class FenwickTree {
private:
    int size;
    vector<int> tree;

public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        FenwickTree bit(2 * n + 2);
        int offset = n + 1;
        
        bit.update(0 + offset, 1);
        
        int runningPrefix = 0;
        long long totalSubarrays = 0;

        for (int x : nums) {
            if (x == target) {
                runningPrefix += 1;
            } else {
                runningPrefix -= 1;
            }
            
            totalSubarrays += bit.query(runningPrefix + offset - 1);
            
            bit.update(runningPrefix + offset, 1);
        }

        return totalSubarrays;
    }
};
