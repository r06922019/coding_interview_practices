class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        cnt = 0
        s = set()
        for num in rolls:
            s.add(num)
            if len(s) == k:
                cnt += 1
                s = set()
        return cnt + 1
