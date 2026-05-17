class Solution {
private:
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    void backtrack(int row, int n, vector<string>& board) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }

            board[row][col] = 'Q';
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);

            backtrack(row + 1, n, board);

            board[row][col] = '.';
            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return result;
    }
};
