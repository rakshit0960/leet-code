class Solution {

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto isPossible = [&](int bananaCount) {
            long long timeReq = 0;
            for (int pile : piles) {
                timeReq += (pile / bananaCount) + bool(pile % bananaCount);
            }
            return timeReq <= h;
        };

        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};