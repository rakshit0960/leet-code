class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i <= n / 2; i++) {
            for (int j = i + 1; j < n - i; j++) {
                int x = i, y = j;
                for (int k = 0; k < 4; k++) {
                    swap(matrix[i][j], matrix[y][n - 1 - x]);
                    int t = x;
                    x = y;
                    y = n - 1 - t;
                }
            }
        }
    }
};