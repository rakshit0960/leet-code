class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int, i: int = 0) -> int:

        @lru_cache(maxsize=None)
        def func(i: int) -> int:
            if i == len(arr): return 0
            curr, res = 0, 0
            for j in range(i, i + min(k, len(arr) - i)):
                curr = max(curr, arr[j])
                res = max(res, curr * (j - i + 1) + func(j + 1))    
            return res
        
        return func(0)