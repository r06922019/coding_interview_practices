class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        def kadane(nums: List[int]) -> Tuple[int, int]:
            ans, ans_len, cur_ans, cur_len = max(nums), 1, 0, 0
            for x in nums:
                # cur_ans= max(cur_ans+x,x)
                if cur_ans+x <= x:
                    cur_ans, cur_len = x, 1
                else:
                    cur_ans, cur_len = cur_ans+x, cur_len+1
                if cur_ans > ans or (cur_ans == ans and cur_len < ans_len):
                    ans, ans_len = cur_ans, cur_len
            return ans, ans_len
        ans1, ans1_len = kadane(nums)
        ans2, ans2_len = kadane([-x for x in nums])
        return max(ans1, sum(nums)+ans2) if ans2_len < len(nums) else ans1
