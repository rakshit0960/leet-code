class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int element1 = -1;
        int element2 = -1;
        int count1 = 0;
        int count2 = 0;


        for (int num: nums) {
            if (count1 == 0 && element2 != num) {
                element1 = num;
            }

            if (count2 == 0 && element1 != num) {
                element2 = num;
            }

            if (element1 == num) count1++;
            else if (element2 == num) count2++;
            else count1--, count2--;
        }

        count1 = 0;
        count2 = 0;
        for (int num: nums) {
            if (num == element1) count1++;
            else if (num == element2) count2++;
        }

        vector<int> res;
        if (count1 > n / 3) res.push_back(element1);
        if (count2 > n / 3) res.push_back(element2);

        return res;
    }
};