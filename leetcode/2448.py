class Solution:
    def minCost(self, nums: List[int], costs: List[int]) -> int:

        def find_out(num_count_list, index: int):
            l = 0
            for num, count in num_cost_list:
                l += count
                if l > index:
                    return num
            return -1

        cost_sum = sum(costs)
        index1, index2 = (cost_sum-1)//2, (cost_sum)//2
        num_cost_list = sorted(zip(nums, costs))
        num1, num2 = find_out(num_cost_list, index1), find_out(
            num_cost_list, index2)
        cost1, cost2 = 0, 0
        for i in range(len(nums)):
            cost1 += abs(nums[i]-num1) * costs[i]
            cost2 += abs(nums[i]-num2) * costs[i]
        return min(cost1, cost2)
