class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (auto obs : obstacles) {
            string s = to_string(obs[0]) + ","+ to_string(obs[1]); 
            st.insert(s);
        }
        int x = 0, y = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0, res = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir - 1 + 4) % 4;
            } else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + directions[dir][0];
                    int ny = y + directions[dir][1];
                    string s = to_string(nx) + ","+ to_string(ny); 
                    if (st.count(s)) break;
                    x = nx;
                    y = ny;
                    res = max(res, x*x + y*y);
                }
            }
        }
        return res;
    }
};