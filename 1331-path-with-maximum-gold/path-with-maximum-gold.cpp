class Solution {
private:
    bool can_visit(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n) return false;
        if (j < 0 || j >= m) return false;
        if (grid[i][j] == 0) return false;
        if (visited[i][j]) return false;
        return true;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        function<int(int, int)> dfs;

        dfs = [&] (int i, int j) {
            visited[i][j] = true;
            int res = grid[i][j];
            for (int k = 0; k < 4; k++) {
                if (!can_visit(i + dy[k], j + dx[k], grid, visited)) continue;
                res = max(res, grid[i][j] + dfs(i + dy[k], j + dx[k]));
            }
            visited[i][j] = false;
            return res;
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j< m; j++) {
                if (grid[i][j] == 0) continue;
                res = max(res, dfs(i, j));
            }
        }
        return res;
    }
};