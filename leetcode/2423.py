class Solution:
    def equalFrequency(self, word: str) -> bool:
        for i in range(len(word)):
            s = word[:i] + word[i+1:]
            c = Counter(s)
            cc = Counter(c.values())
            if len(cc) == 1:
                return True
        return False
