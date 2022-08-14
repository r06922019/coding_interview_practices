class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        c2 = Counter()
        for w2 in words2:
            _c2 = Counter(w2)
            for k in _c2:
                c2[k] = max(c2[k], _c2[k])
        ans = []
        for w1 in words1:
            c1 = Counter(w1)
            if all([c1[k] >= c2[k] for k in c2]):
                ans.append(w1)
        return ans
