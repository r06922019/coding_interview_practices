class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        c1, c2 = Counter(ransomNote), Counter(magazine)
        for k in c1:
            if k not in c2 or c1[k] > c2[k]:
                return False
        return True
