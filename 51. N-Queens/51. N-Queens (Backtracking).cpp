class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> rows(n, -1);
        vector<bool> columns(n, false), diagonals(2 * n - 1, false), antiDiagonals(2 * n - 1, false);
        vector<vector<string>> answers;
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                vector<string> answer(n, string(n, '.'));
                for (int i = 0; i < n; i++)
                    answer[i][rows[i]] = 'Q';
                answers.emplace_back(answer);
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
        return answers;
    }
};