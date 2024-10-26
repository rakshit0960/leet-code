class Solution:
    def countOrders(self, n: int) -> int:
        return int(factorial(2 * n) // 2**n) % int(1e9 + 7)