class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        l = min(len(word1), len(word2))
        return "".join([a+b for a, b in zip(word1, word2[:l])]) + word1[l:] + word2[l:]
