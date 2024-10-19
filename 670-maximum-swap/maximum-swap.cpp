class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();

        int maxElem = str[n- 1];
        int maxIndx = n - 1;
        int spawIndex1 = n - 1;
        int swapIndex2 = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (str[i] < maxElem) {
                spawIndex1 = i;
                swapIndex2 = maxIndx;
            }

            if (str[i] > maxElem) {
                maxElem = str[i];
                maxIndx = i;
            }
        }

        swap(str[spawIndex1], str[swapIndex2]);
        return stoi(str);
    }
};