class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;

        int prev  = 0;
        for (string& row : bank) {
            int count = 0;
            for (char& cell : row) count += cell - '0';
            res += count * prev;
            if (count != 0) prev = count;
        }
        
        return res;
    }
};