class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda el: -el[1])
        index, loaded, ans = 0, 0, 0
        while loaded < truckSize and index < len(boxTypes):
            cur = min(boxTypes[index][0], truckSize-loaded)
            ans += cur * boxTypes[index][1]
            loaded += cur
            index += 1
        return ans
