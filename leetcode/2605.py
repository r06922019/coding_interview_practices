class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        for i in range(10):
            if i in nums1 and i in nums2:
                return i
        a, b = str(min(nums1)), str(min(nums2))
        return min(int(a+b), int(b+a))
