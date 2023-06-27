class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        # return sum([mat[i][j] for i in range(n) for j in range(n) if i == j or i+j == n-1 ])
        # ans = 0
        # for i in range(n):
        #     for j in range(n):
        #         if i == j or i+j == n-1:
        #             ans += mat[i][j]
        # return ans
        ans = 0
        for i in range(n):
            ans += mat[i][i]
            if i != n-1-i:
                ans += mat[i][n-1-i]
        return ans
