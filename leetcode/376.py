class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        u, d = [1], [1]
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                u.append(u[-1])
                d.append(d[-1])
            elif nums[i-1] < nums[i]:
                u.append(d[-1]+1)
                d.append(d[-1])
            else:
                d.append(u[-1]+1)
                u.append(u[-1])
        return max(u[-1], d[-1])
