class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        d1, d2, n = [], [], len(img1)
        for i in range(n):
            for j in range(n):
                if img1[i][j] == 1:
                    d1.append([i, j])
                if img2[i][j] == 1:
                    d2.append([i, j])

        counts = Counter()
        for p1 in d1:
            for p2 in d2:
                counts[(p2[0]-p1[0], p2[1]-p1[1])] += 1
        return max(counts.values()) if len(counts) else 0
