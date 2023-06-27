class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        in_degrees = [0]*n
        for e in edges:
            a, b = e
            in_degrees[b] += 1
        return [i for i in range(n) if in_degrees[i] == 0]
