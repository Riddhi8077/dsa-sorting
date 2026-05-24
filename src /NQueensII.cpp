class Solution {
private:
    int solutionCount = 0;
    unordered_set<int> cols;
    unordered_set<int> posDiag; 
    unordered_set<int> negDiag;

    void backtrack(int row, int n) {
        if (row == n) {
            solutionCount++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }

            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);

            backtrack(row + 1, n);

            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
        }
    }

public:
    int totalNQueens(int n) {
        solutionCount = 0;
        backtrack(0, n);
        return solutionCount;
    }
};
