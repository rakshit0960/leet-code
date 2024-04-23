class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> inOrder(n, 0);
        vector<int> adj[n]; 

        if (n == 1) return { 0 };

        // fill adjMatrix and inOrder array
        for (auto& edge : edges) {
            int node = edge[0], adjNode = edge[1];
            inOrder[node]++;
            inOrder[adjNode]++;
            adj[node].push_back(adjNode);
            adj[adjNode].push_back(node);
        }

        queue<int> leaves;

        // add leaves nodes to the queue
        for (int i = 0; i < n; i++) {
            if (inOrder[i] == 1) {
                leaves.push(i);
            }    
        }
        
        // delete leaves nodes and and add new leaves to the queue until n <= 2 node remains
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

        // add remaining nodes to the result
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};