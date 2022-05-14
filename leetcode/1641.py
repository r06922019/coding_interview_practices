class Solution:
    def countVowelStrings(self, n: int) -> int:
        cur = {c: 1 for c in "aeiou"}
        for _ in range(n-1):
            nex = {}
            tmp = 0
            for c in "uoiea":
                tmp += cur[c]
                nex[c] = tmp
            cur = nex
        return sum(cur.values())
