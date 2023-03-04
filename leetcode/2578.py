class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        a, b = "", ""
        for c in s:
            if len(a) < len(b):
                a += c
            else:
                b += c
        return int(a) + int(b)
