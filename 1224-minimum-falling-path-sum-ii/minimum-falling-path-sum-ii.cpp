class Solution {
public:
    int minFallingPathSum(vector<vector<int>> grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int res = INT_MAX;
                for (int k = 0; k < cols; k++) {
                    if (k == j) continue;
                    res = min(grid[i - 1][k], res); 
                }
                grid[i][j] += res;
            }
        }

        return *min_element(grid[rows - 1].begin(), grid[rows - 1].end());
    }
};