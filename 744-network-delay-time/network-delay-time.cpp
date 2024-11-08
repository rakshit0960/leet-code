class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if (n == 1) return -1;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        for (int i = 0; i < n; i++) {
            for (auto edge : times) {
                int u = edge[0];
                int v = edge[1];
                int t = edge[2];
                dist[v] = min(dist[u] + t, dist[v]);
            }
        }

        if (*max_element(dist.begin() + 1, dist.end()) == 1e9) return -1;
        else return *max_element(dist.begin() + 1, dist.end());
        
    }
};