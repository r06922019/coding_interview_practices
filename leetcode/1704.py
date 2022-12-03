class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        l = len(s)//2
        return len([x for x in s[:l] if x in vowels]) == len([x for x in s[l:] if x in vowels])
