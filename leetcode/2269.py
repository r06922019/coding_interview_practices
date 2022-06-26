class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        ans = 0
        num_str = str(num)
        for i in range(len(num_str)-k+1):
            sub_int = int(num_str[i:i+k])
            if sub_int > 0 and num % sub_int == 0:
                ans += 1
        return ans
