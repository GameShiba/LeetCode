class Solution {
public:
    int totalNQueens(int n) {
        vector<int> rows(n, -1);
        vector<bool> columns(n, false), diagonals(2 * n - 1, false), antiDiagonals(2 * n - 1, false);
        int count = 0;
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                count++;
                return;
            }
            for (int column = 0; column < n; column++) {
                if (!(rows[row] >= 0 || columns[column] || diagonals[row + n - 1 - column] || antiDiagonals[row + column])) {
                    rows[row] = column, columns[column] = diagonals[row + n - 1 - column] = antiDiagonals[row + column] = true;
                    backtrack(row + 1);
                    rows[row] = -1, columns[column] = diagonals[row + n - 1 - column] = antiDiagonals[row + column] = false;
                }
            }
        };
        backtrack(0);
        return count;
    }
};