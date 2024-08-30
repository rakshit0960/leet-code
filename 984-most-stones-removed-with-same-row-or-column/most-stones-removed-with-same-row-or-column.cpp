class UnionFind {
    private:
        vector<int> parent;
        vector<int> size;
        int components;
        int n;
    public:
        UnionFind(int size) {
            components = n = size;
            parent = vector<int>(n);
            this->size = vector<int>(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int root) {
            if (parent[root] == root) return root;
            int res = find(parent[root]);
            parent[root] = res;
            return res;
        }

        void union_(int p1, int p2) {
            int r1 = find(p1);
            int r2 = find(p2);
            
            if (r1 == r2) return;
            components--;
            if (size[r1] < size[r2]) {
                parent[r1] = r2;
                size[r2] += size[r1];
            }
            else {
                parent[r2] = r1;
                size[r1] += size[r2];
            }
        }

        int componentsCount() {
            return components;
        }
};

class Solution {

public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        UnionFind uf(n);

        for (int i = 0; i < n; i++) {
            int row = stones[i][1];
            int col = stones[i][0];
            if (rows.count(row)) 
                uf.union_(i, rows[row]);
            else 
                rows[row] = i;

            if (cols.count(col)) 
                uf.union_(i, cols[col]);
            else 
                cols[col] = i;
        }

        return n - uf.componentsCount();

    }
};