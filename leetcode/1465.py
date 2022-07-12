class Solution:
    def get_diff(self, arr):
        return [(arr[i] - arr[i-1]) for i in range(1, len(arr))]
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        hh = self.get_diff([0]+sorted(horizontalCuts)+[h])
        ww = self.get_diff([0]+sorted(verticalCuts)+[w])
        return (max(ww)*max(hh)) % int(1e9+7)
