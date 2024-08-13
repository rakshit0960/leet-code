class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        int up = 0;
        int down = rows - 1;
        int right = cols - 1;
        int left = 0;

        vector<int> res;
        while (right >= left && up <= down) {
            // right
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[up][i]);
            }
            up++;

            if (up > down) break;

            // down
            for (int i = up; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            if (right < left) break;
            
            // left 
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[down][i]);
            }
            down--;

            if (up > down) break;

            // up 
            for (int i = down; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
            
            if (right < left) break;

        } 
        return res;
    }
};