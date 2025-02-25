class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        codes = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                 "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
        return len(Counter(["".join([codes[ord(c)-ord('a')] for c in w]) for w in words]))
