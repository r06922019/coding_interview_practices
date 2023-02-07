class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return sum([[x, y] for x, y in zip(nums[:n], nums[n:])], [])
