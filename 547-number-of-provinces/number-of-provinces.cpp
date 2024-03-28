class Solution {
public:
    void dfs(int curr, vector<vector<int>>& isConnected, vector<bool>& visited) {
        int n = isConnected.size();
        visited[curr] = true;

        for (int i = 0; i < n; i++) {
            if (isConnected[curr][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        stack<int> stk;
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) count++;
            dfs(i, isConnected, visited);
        }
        return count;
    }
};