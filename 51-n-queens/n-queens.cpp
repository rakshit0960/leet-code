class Solution {
public:
    bool isvalid(int row, int col, vector<string>& board) {
        int n = board.size();
        // vertically
        for (int i = 0; i < n; i++) {
            // if (i != col && board[row][i] == 'Q') return false;
            if (i != row && board[i][col] == 'Q') return false;
        }

        // check diganoly
        for (int i = -min(col, n - row - 1); i <= min(row, n - col - 1); i++) {
            if (i == 0) continue;
            if (board[row - i][col + i] == 'Q') return false;
        }
        for (int i = -min(col, row); i <= min(n - row - 1, n - col - 1); i++) {
            if (i == 0) continue;
            if (board[row + i][col + i] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        function<void(int, int)> dfs;
        dfs = [&] (int row, int n) {
            if (row >= n) {
                res.push_back(board);
                return;
            }

            for (int j = 0; j < n; j++) {
                if (isvalid(row, j, board)) {
                    board[row][j] = 'Q';
                    dfs(row + 1, n);
                    board[row][j] = '.';
                }
            }
        };

        dfs(0, n);
        return res;
    }
};