class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([x for x in s.strip().split()][::-1])
