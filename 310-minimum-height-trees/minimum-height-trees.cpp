class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> inOrder(n, 0);
        vector<int> adj[n];

        if (n == 1) return { 0 };

        for (auto& edge : edges) {
            int node = edge[0];
            int adjNode = edge[1];
            inOrder[node]++;
            inOrder[adjNode]++;

            adj[node].push_back(adjNode);
            adj[adjNode].push_back(node);
        }

        queue<int> que;
        for (int i = 0; i < n; i++) {
            cout << inOrder[i] << " ";
            if (inOrder[i] == 1) {
                que.push(i);
            }    
        }
        que.push(-1);

        vector<int> res = {}; 
        while (!que.empty()){
            int node = que.front();
            que.pop();
            
            if (node == -1) {
                if (que.empty()) return res;
                res = {};
                que.push(-1);
                continue;
            }

            res.push_back(node);
            
            for (int adjNode : adj[node]) {
                inOrder[adjNode]--;
                if (inOrder[adjNode] == 1) que.push(adjNode);
            }
        }

        return res;
    }
};