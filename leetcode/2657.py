class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        c1, c2, n = Counter(), Counter(), len(A)
        ans = []
        for i in range(n):
            c1[A[i]] += 1
            c2[B[i]] += 1
            ans.append(0)
            for i in range(1, n+1):
                if c1[i] == c2[i] and c1[i] != 0:
                    ans[-1] += 1
        return ans
