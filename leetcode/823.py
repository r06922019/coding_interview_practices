class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        d = {}
        for index, num in enumerate(arr):
            tmp_ans = 1
            # for x in range(2,num-1):
            for i in range(index):
                x = arr[i]
                if num % x == 0:
                    y = num//x
                    if y in d:
                        tmp_ans += d[x]*d[y]
            d[num] = tmp_ans
        return sum(d.values()) % int(1e9+7)
