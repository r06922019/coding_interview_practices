class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        def simplify(point: List[int]):
            gcd = math.gcd(abs(point[0]), abs(point[1]))
            sign = -1 if point[0] * point[1] < 0 else 1
            if point[1] == 0:
                return [1, 0]
            return [abs(point[0])/gcd, sign*abs(point[1])/gcd]
        max_val = 1
        for i in range(len(points)):
            c = Counter()
            point0 = points[i]
            for j in range(len(points)):
                if j != i:
                    vec = [points[j][0] - point0[0], points[j][1] - point0[1]]
                    vec = simplify(vec)
                    c[tuple(vec)] += 1
            if len(c):
                max_val = max(max_val, max(c.values())+1)
        return max_val
