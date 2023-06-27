class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        conv = [nums[0]*2]
        max_x = nums[0]
        for x in nums[1:]:
            max_x = max(x, max_x)
            conv.append(x + max_x)
        ans = [conv[0]]
        for x in conv[1:]:
            ans.append(ans[-1]+x)
        return ans
