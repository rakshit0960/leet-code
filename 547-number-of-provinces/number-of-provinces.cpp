class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> que;
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) count++;
            que.push(i);
            while (!que.empty()) {
                int node = que.front();
                visited[node] = true;
                que.pop();

                for (int adj = 0; adj < n; adj++) {
                    if (isConnected[node][adj] == 1 && !visited[adj])
                        que.push(adj);
                }
            }
        }
        return count;
    }
};