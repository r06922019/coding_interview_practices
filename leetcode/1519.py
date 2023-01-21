class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        neighbors = {}
        for e in edges:
            for x in e:
                if x not in neighbors:
                    neighbors[x] = []
            a, b = e
            neighbors[a].append(b)
            neighbors[b].append(a)
        ans: Dict[int, int] = {}

        def traverse(node: int, parent: int):
            c = Counter([labels[node]])
            for neigh in neighbors[node]:
                if neigh != parent:
                    cc = traverse(neigh, node)
                    for k, v in cc.items():
                        c[k] += v
            ans[node] = c[labels[node]]
            return c
        traverse(0, 0)
        ret = [0]*len(ans)
        for k, v in ans.items():
            ret[k] = v
        return ret
