class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int dx[] = { 1, 0, -1, 0 };
        const int dy[] = { 0, 1, 0, -1 };
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> que;

        int freshCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) 
                    que.push({i, j});
                else if (grid[i][j] == 1)
                    freshCount += 1;
            }
        }
        que.push({-1, -1});

        int count = -1;
        while (!que.empty()) {  
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            if (i == -1 || j == -1) {
                count += 1;
                if (que.empty()) break;
                que.push({-1, -1});
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int x = i + dy[k];
                int y = j + dx[k];
                
                if (x < 0 || x >= rows) continue;
                if (y < 0 || y >= cols) continue;
                if (grid[x][y] != 1) continue;

                grid[x][y] = 2;
                freshCount--;
                que.push({x, y});
            }
        }

        return (freshCount) ? -1 : count;
    }
};