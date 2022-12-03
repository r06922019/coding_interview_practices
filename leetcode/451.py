class Solution:
    def frequencySort(self, s: str) -> str:
        c = Counter(s)
        return "".join([x[0]*x[1] for x in sorted(c.items(),  key=lambda el:-el[1])])
