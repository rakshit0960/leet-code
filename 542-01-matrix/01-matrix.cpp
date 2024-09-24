class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        const int dx[] = { 0, 1, 0, -1 };
        const int dy[] = { 1, 0, -1, 0 };

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> res(n, vector<int>(m, 0));


        queue<pair<int, int>> que;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    que.push({i, j});
                }
            }
        }

        int level = 0;

        while (!que.empty()) {
            int size = que.size();
            for (int l = 0; l < size; l++) {
                auto node = que.front();
                que.pop();
                int ni = node.first;
                int nj = node.second;
                // cout << ni << " " << nj << endl;
                if (visited[ni][nj]) continue;
                visited[ni][nj] = true;
                if (mat[ni][nj] == 1) res[ni][nj] = level;

                for (int k = 0; k < 4; k++) {
                    int ai = ni + dx[k];
                    int aj = nj + dy[k];
                    if (ai < 0 || ai >= n || aj < 0 || aj >= m || visited[ai][aj]) continue;
                    // cout << ai << " " << aj << endl;
                    que.push({ai, aj});
                }
            }
            level++;
        }

        return res;
    }
};