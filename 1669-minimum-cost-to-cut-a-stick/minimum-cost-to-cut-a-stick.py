class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        cuts = [0] + cuts + [n]

        @cache
        def func(l, r):
            if (abs(r - l) <= 1):
                return 0
                
            res = float('inf')
            for i in range(l + 1, r):
                res = min(res, cuts[r] - cuts[l] + func(l, i) + func(i, r))
                print(res)
            return res

        return func(0, len(cuts) - 1)