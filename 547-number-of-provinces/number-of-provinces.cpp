class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        stack<int> stk;
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) count++;
            stk.push(i);
            while (!stk.empty()) {
                int node = stk.top();
                visited[node] = true;
                stk.pop();

                for (int adj = 0; adj < n; adj++) {
                    if (isConnected[node][adj] == 1 && !visited[adj])
                        stk.push(adj);
                }
            }
        }
        return count;
    }
};