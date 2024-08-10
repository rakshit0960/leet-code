class Solution {

public:
    int totalNQueens(int n) {
        unordered_set<int> cols, posDig, negDig;

        function<int(int)> dfs;
        dfs = [&] (int row) {
            if (row >= n) return 1;
            
            int res = 0;
            for (int col = 0; col < n; col++) {
                if (!cols.count(col) && !posDig.count(row - col) && !negDig.count(row + col)) {
                    cols.insert(col);
                    posDig.insert(row - col);
                    negDig.insert(row + col);
                    res += dfs(row + 1);
                    cols.erase(col);
                    posDig.erase(row - col);
                    negDig.erase(row + col);

                }
            }

            return res;
        };


        return dfs(0);
    }
};