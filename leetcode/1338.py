class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        items = sorted(Counter(arr).items(), reverse=True, key=lambda p: p[1])
        ans, cur_size, half_size = 0, 0, len(arr)/2
        for item in items:
            cur_size += item[1]
            ans += 1
            if cur_size >= half_size:
                break
        return ans
