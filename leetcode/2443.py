class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        for a in range(num+1):
            if a + int(str(a)[::-1]) == num:
                return True

        return False
