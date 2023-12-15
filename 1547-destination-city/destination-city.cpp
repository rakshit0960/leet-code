class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> src;

        for (auto& path : paths) {
            src.insert(path[0]);    
        }

        for (auto& path : paths) {
            if (!src.count(path[1])) return path[1];  
        }

        return "cycle";
    }
};