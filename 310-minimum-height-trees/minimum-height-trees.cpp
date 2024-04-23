class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> inOrder(n, 0);
        vector<int> adj[n];

        if (n == 1) return { 0 };

        for (auto& edge : edges) {
            int node = edge[0], adjNode = edge[1];
            inOrder[node]++;
            inOrder[adjNode]++;
            adj[node].push_back(adjNode);
            adj[adjNode].push_back(node);
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (inOrder[i] == 1) {
                leaves.push(i);
            }    
        }
        
        while (n > 2){
            int size = leaves.size();
            for (int i = 0; i < size; i++) {
                int node = leaves.front();
                leaves.pop();
                n--;
                for (int adjNode : adj[node]) {
                    inOrder[adjNode]--;
                    if (inOrder[adjNode] == 1) leaves.push(adjNode);
                }
            }
        }

        vector<int> res; 
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};