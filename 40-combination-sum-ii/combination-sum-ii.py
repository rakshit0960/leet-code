class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        currList = []

        def dfs(i, currSum):
            if currSum == target:
                res.append(currList.copy())
                return
            if currSum > target:
                return 
            if i >= len(candidates):
                return 

            currList.append(candidates[i])
            dfs(i + 1, currSum + candidates[i]) 
            currList.pop()

            for j in range(i + 1, len(candidates) + 1):
                if j == len(candidates) or candidates[j] != candidates[i]:
                    dfs(j, currSum)
                    break

        dfs(0, 0)
        return res
            
            