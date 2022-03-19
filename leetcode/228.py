class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        l = []
        for num in nums:
            if len(l) == 0 or l[-1][-1] != num-1:
                l.append([num, num])
            else:
                l[-1][-1] = num
        return [str(p[0]) if p[0] == p[1] else "%d->%d" % (p[0], p[1]) for p in l]
