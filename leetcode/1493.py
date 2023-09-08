class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        def fill_in(nums):
            arr = [0] * len(nums)
            ones = 0
            for i, x in enumerate(nums):
                arr[i] = ones
                if x == 0:
                    ones = 0
                else:
                    ones += 1
            return arr

        l, r = fill_in(nums), fill_in(nums[::-1])[::-1]
        return max([
            l[i] + r[i] for i in range(len(nums))
        ])
