class Solution:
    def countVowelPermutation(self, n: int) -> int:
        if n == 1:
            return 5
        d = {c: 1 for c in "aeiou"}
        while n >= 2:
            d = {
                'a': d['e'],
                'e': d['a']+d['i'],
                'i': d['a']+d['e']+d['o']+d['u'],
                'o': d['i']+d['u'],
                'u': d['a'],
            }
            n -= 1
        return sum(d.values()) % int(1e9+7)
