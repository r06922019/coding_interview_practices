class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        n = len(nums)
        unique_set = set()
        prefix_sum = [0]
        for num in nums:
            prefix_sum.append(prefix_sum[-1])
            if num % p == 0:
                prefix_sum[-1] += 1

        for i in range(n):
            for j in range(i, n):
                if prefix_sum[j+1] - prefix_sum[i] <= k:
                    unique_set.add(tuple(nums[i:j+1]))
        return len(unique_set)
