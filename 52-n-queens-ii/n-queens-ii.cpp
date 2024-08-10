class Solution {
    bool isValid(vector<int>& board, int row, int index) {
        int n = board.size();

        // check vertical
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            if (board[i] & (1<<index)) return false;
        }

        // check diagoal 
        int i = row - 1, j = index + 1;
        while(i >= 0 && j < n) {
            if (board[i] & (1<<j)) return false;
            i--;
            j++;
        }
        
        i = row + 1, j = index - 1;
        while (i < n && j >= 0) {
            if (board[i] & (1<<j)) return false;
            i++;
            j--;
        }

        i = row + 1, j = index + 1;
        while (i < n && j < n) {
            if (board[i] & (1<<j)) return false;
            i++;
            j++;
        }

        i = row - 1, j = index - 1;
        while (i >= 0 && j >= 0) {
            if (board[i] & (1<<j)) return false;
            i--;
            j--;
        }

        return true;
    }

public:
    int totalNQueens(int n) {
        vector<int> board(n, 0);

        function<int(int)> dfs;
        dfs = [&] (int row) {
            if (row >= n) return 1;
            
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (isValid(board, row, i)) {
                    board[row] = (1<<i);
                    res += dfs(row + 1);
                    board[row] = 0;
                }
            }

            return res;
        };


        return dfs(0);
    }
};