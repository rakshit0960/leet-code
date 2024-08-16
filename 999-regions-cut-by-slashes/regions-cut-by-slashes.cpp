class Solution {
private:
    bool validCell(vector<vector<int>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || i >= rows) return false;
        if (j < 0 || j >= cols) return false;
        if (grid[i][j] == 1) return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        grid[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (validCell(grid, ni, nj)) {
                dfs(grid, ni, nj);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int rows2 = rows * 3;
        int cols2 = cols * 3;

        vector<vector<int>> newGrid(rows2, vector<int>(cols2, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int r = i * 3;
                int c = j * 3;

                if (grid[i][j] == '\\') {
                    newGrid[r][c] = 1;
                    newGrid[r + 1][c + 1] = 1;
                    newGrid[r + 2][c + 2] = 1;
                }
                else if (grid[i][j] == '/') {
                    newGrid[r][c + 2] = 1;
                    newGrid[r + 1][c + 1] = 1;
                    newGrid[r + 2][c] = 1;
                }
            }
        }

        int regionCount = 0;
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                if (newGrid[i][j] == 1) continue;
                dfs(newGrid, i, j);
                regionCount++;
            }
        }

        return regionCount;
    }
};