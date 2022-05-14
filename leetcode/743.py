class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        k -= 1
        max_times: List[int] = [-1] * n
        unvisited = set([i for i in range(n)])
        adj_list: Dict[int, List[List[int]]] = {}
        for edge in times:
            u, v, w = edge[0]-1, edge[1]-1, edge[2]
            if u not in adj_list:
                adj_list[u] = []
            adj_list[u].append([v, w])

        max_times[k] = 0
        pq = []
        heappush(pq, (0, k))
        while len(pq):
            top = heappop(pq)
            t, x = top
            if x not in unvisited:
                continue
            unvisited.remove(x)
            if x not in adj_list:
                continue
            for v, w in adj_list[x]:
                new_time = t + w
                if max_times[v] == -1 or new_time < max_times[v]:
                    max_times[v] = new_time
                    heappush(pq, (new_time, v))

        return max(max_times) if len(unvisited) == 0 else -1
