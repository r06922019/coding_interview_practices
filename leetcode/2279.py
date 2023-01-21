class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        spaces = sorted([x-y for x, y in zip(capacity, rocks)])
        cur, l = 0, 0
        while l < len(spaces) and cur+spaces[l] <= additionalRocks:
            cur, l = cur+spaces[l], l+1
        return l
