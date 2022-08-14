class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        d = Counter()
        for i in items1 + items2:
            d[i[0]] += i[1]
        return sorted(list(d.items()), key=lambda x: x[0])
