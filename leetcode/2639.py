class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        return [max([len(str(x)) for x in g]) for g in zip(*grid)]
