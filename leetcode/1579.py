class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:

        def find_group(group, x):
            if group[x] != x:
                group[x] = find_group(group, group[x])
            return group[x]

        def merge_group(group, a, b):
            ga = find_group(group, a)
            gb = find_group(group, b)
            group[ga] = group[gb] = min(ga, gb)
            return group[ga]

        ans = 0
        group_all = list(range(n))
        for t, a, b in edges:
            a, b = a-1, b-1
            if t == 3:
                if find_group(group_all, a) != find_group(group_all, b):
                    merge_group(group_all, a, b)
                else:
                    ans += 1

        group_alice = group_all.copy()
        for t, a, b in edges:
            a, b = a-1, b-1
            if t == 1:
                if find_group(group_alice, a) != find_group(group_alice, b):
                    merge_group(group_alice, a, b)
                else:
                    ans += 1

        if sum([find_group(group_alice, i) for i in range(n)]) != 0:
            return -1  # unconnected for alice

        group_bob = group_all.copy()
        for t, a, b in edges:
            a, b = a-1, b-1
            if t == 2:
                if find_group(group_bob, a) != find_group(group_bob, b):
                    merge_group(group_bob, a, b)
                else:
                    ans += 1
        if sum([find_group(group_bob, i) for i in range(n)]) != 0:
            return -1  # unconnected for bob

        return ans
