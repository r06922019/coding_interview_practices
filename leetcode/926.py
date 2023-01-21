class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        c = Counter(s)
        zeros, ones = c['0'], c['1']
        min_val = min(zeros, ones)
        for ch in s:
            if ch == '0':
                zeros -= 1
            if ch == '1':
                ones -= 1
            min_val = min(min_val, zeros + c['1'] - ones)
        return min_val
