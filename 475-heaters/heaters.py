class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        
        def isPossible(radius: int) -> bool:
            i, j = 0, 0
            while i < len(houses):
                if j >= len(heaters) or houses[i] < heaters[j] - radius:
                    return False
                elif houses[i] > heaters[j] + radius:
                    j += 1
                else:
                    i += 1
            return True

        low, high, res = 0, int(1e9), -1
        while low <= high:
            mid = low + (high - low) // 2
            if isPossible(mid):
                res = mid
                high = mid - 1
            else:
                low = mid + 1

        return res

