class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] == 0) continue;
                mat[i][j] = mat[i][j - 1] + 1;
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minWidth = mat[i][j];
                for (int k = i; k < m; k++) {
                    if (minWidth == 0) break;
                    minWidth = min(mat[k][j], minWidth);
                    count += minWidth;
                } 
            }
        }
        return count;

    }
};