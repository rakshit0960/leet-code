class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mp;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mp[i - j].push_back(mat[i][j]);        
            }
        }

        for (auto& it: mp) {
            sort(it.second.begin(), it.second.end(), [](int a, int b) {return a > b;});
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                auto& vect = mp[i - j];
                mat[i][j] = vect[vect.size() - 1];
                vect.pop_back();
            }
        }

        return mat;

    }
};