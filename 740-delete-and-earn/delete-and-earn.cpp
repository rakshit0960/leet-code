class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        vector<int> arr;
        for (auto it : freq) arr.push_back(it.first);
        sort(arr.begin(), arr.end());
        const int n = arr.size();

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = arr[0] * freq[arr[0]];
        cout << dp[0] << " " << dp[1]  << " ";
        for (int i = 2; i <= n; i++) {
            int currNum = arr[i - 1];
            int currEarn = freq[currNum] * currNum;

            if (arr[i - 2] == arr[i - 1] - 1) {
                dp[i] = max(currEarn + dp[i - 2], dp[i - 1]);
            } else {
                dp[i] = currEarn + dp[i - 1];
            }
            cout << dp[i] << " ";
        }

        return dp[n];
    }
};