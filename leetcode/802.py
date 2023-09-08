class Solution:
    def eventualSafeNodes(self, graph_: List[List[int]]) -> List[int]:
        n: int = len(graph_)
        graph: List[Set[int]] = [set(graph_[i]) for i in range(n)]
        reverse_adj_lists: List[List[int]] = [list() for _ in range(n)]
        for i in range(n):
            for j in graph[i]:
                reverse_adj_lists[j].append(i)
        ans = [i for i in range(n) if len(graph[i]) == 0]
        st = ans.copy()
        while len(st):
            cur = st.pop()
            for nex in reverse_adj_lists[cur]:
                graph[nex].remove(cur)
                if len(graph[nex]) == 0:
                    st.append(nex)
                    ans.append(nex)
        return sorted(ans)
