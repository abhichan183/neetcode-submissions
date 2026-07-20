class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col.resize(n, false);
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);

        solve(0, n);
        return ans;
    }

    void solve(int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c]) continue;
            if (diag1[row - c + n - 1]) continue;
            if (diag2[row + c]) continue;

            board[row][c] = 'Q';
            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;

            solve(row + 1, n);

            board[row][c] = '.';
            col[c] = false;
            diag1[row - c + n - 1] = false;
            diag2[row + c] = false;
        }
    }
};