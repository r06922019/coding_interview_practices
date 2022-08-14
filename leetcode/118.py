class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        for _ in range(numRows-1):
            ans.append(
                [1] + [a+b for a, b in zip(ans[-1][1:], ans[-1][:-1])] + [1])
        return ans
