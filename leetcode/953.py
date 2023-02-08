class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        d = { c:chr(ord('a')+i) for i,c in enumerate(order) }
        def convert(word:str) -> str:
            return "".join([d[c] for c in word])
        return sorted(words, key=convert) == words
