class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[0] * m for _ in range(n)]
        maxSquareSize = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '0':
                    continue
                if i == 0 or j == 0:
                    dp[i][j] = int(matrix[i][j])
                    maxSquareSize = max(maxSquareSize, dp[i][j])
                    continue
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                maxSquareSize = max(maxSquareSize, dp[i][j])
    
        return maxSquareSize * maxSquareSize 