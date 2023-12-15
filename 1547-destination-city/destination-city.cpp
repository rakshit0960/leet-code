class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        bool has_outgoing = true;
        string city = paths[0][0];

        while (has_outgoing) {
            has_outgoing = false;

            for (auto& path : paths) {
                if (path[0] == city) {
                    city = path[1];
                    has_outgoing =true;
                }
            }
        }

        return city;
    }
};