class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        def isPalin(s: str) -> bool:
            for i in range(len(s)//2):
                if s[i] != s[len(s)-i-1]:
                    return False
            return True
        def convert_to_base(num: int, base: int) -> str:
            ret = []
            while num:
                ret.append(num % base)
                num = num // base
            return "".join([str(x) for x in ret[::-1]])
        for base in range(2, n-1):
            if not isPalin(convert_to_base(n, base)):
                return False
        return True
