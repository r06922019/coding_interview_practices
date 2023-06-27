class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        ans: List[bool] = [False]*len(queries)
        edgeList.sort(key=lambda p: p[2])
        edge_index = 0

        groups = list(range(n))
        group_to_max_edge = [0] * n

        def find_group(i):
            if groups[i] != i:
                groups[i] = find_group(groups[i])
            return groups[i]

        def merge_group(a, b, e):
            ga, gb = find_group(a), find_group(b)
            groups[gb] = ga
            group_to_max_edge[ga] = max(
                group_to_max_edge[ga], group_to_max_edge[gb], e)

        def in_same_group(a, b):
            ga, gb = find_group(a), find_group(b)
            if ga != gb:
                return -1
            return ga

        def find_max_egde_between(a, b):
            g = in_same_group(a, b)
            if g == -1:
                return -1
            return group_to_max_edge[g]

        for i, q in sorted(list(enumerate(queries)), key=lambda p: p[1][2]):
            while(edge_index < len(edgeList) and edgeList[edge_index][2] < q[2]):
                a, b, e = edgeList[edge_index]
                if in_same_group(a, b) == -1:
                    merge_group(a, b, e)
                edge_index += 1
            a, b, e = q
            f = find_max_egde_between(a, b)
            if f >= 0 and f < e:
                ans[i] = f

        return ans
