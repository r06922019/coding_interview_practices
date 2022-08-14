class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = 0
        nums.append(1)
        zeros = 0
        for num in nums:
            if num == 0:
                zeros += 1
            else:
                ans += zeros * (zeros+1) // 2
                zeros = 0
        return ans
