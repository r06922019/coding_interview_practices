class Solution:
    def oddString(self, words: List[str]) -> str:
        d = {}
        for w in words:
            k = []
            for i in range(1, len(w)):
                k.append(ord(w[i]) - ord(w[i-1]))
            k = tuple(k)
            if k not in d:
                d[k] = []
            d[k].append(w)
        for k in d:
            if len(d[k]) == 1:
                return d[k][0]
