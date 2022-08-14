class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        nums = nums[::-1]
        cost = 0
        cur_min = nums[0]
        for num in nums:
            if num > cur_min:
                pieces = ceil(num / cur_min)
                cost += pieces - 1
                if num % cur_min != 0:
                    cur_min = num // pieces
            elif num < cur_min:
                cur_min = num
        return cost
