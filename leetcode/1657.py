class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # def gather(w:str):
        #     c = Counter(w)
        #     return sorted(c.keys()) + sorted(c.values())
        # return gather(word1) == gather(word2)
        c1, c2 = Counter(word1), Counter(word2)
        for x in range(26):
            if (chr(ord('a')+x) in c1) ^ (chr(ord('a')+x) in c2):
                return False
        return Counter(c1.values()) == Counter(c2.values())
