class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;

        function<void(int, int)> comb;
        comb = [&] (int num, int sum) {
            if (num < 0 || curr.size() > k) return;
            if (curr.size() == k) {
                if (sum == n) res.push_back(curr);
                return;
            } 

            comb(num - 1, sum);
            curr.push_back(num);
            comb(num - 1, sum + num);
            curr.pop_back();
        }; 

        comb(9, 0);
        return res;
    }
};