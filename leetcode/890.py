class Solution:
    def check(self, word: str, pattern: str) -> bool:
        mapped_to, mapped_from = {}, {}
        for w, p in zip(word, pattern):
            if w not in mapped_to and p not in mapped_from:
                mapped_to[w], mapped_from[p] = p, w
            elif w in mapped_to and p in mapped_from:
                if mapped_to[w] != p or mapped_from[p] != w:
                    return False
            else:
                return False
        return True

    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        return [w for w in words if self.check(w, pattern)]
