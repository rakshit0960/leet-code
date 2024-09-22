/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        Node* res = new Node(node->val);
        visited[node] = res;
        for (Node* adj : node->neighbors) {
            if (!visited.count(adj))
                res->neighbors.push_back(cloneGraph(adj));
            else 
                res->neighbors.push_back(visited[adj]);
        }
        return res;
    }
};