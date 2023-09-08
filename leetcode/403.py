class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if stones[1] != stones[0] + 1:
            return False
        n = len(stones)
        stone_to_index = {
            stone: i for i, stone in enumerate(stones)
        }
        index_to_k: Dict[int, Set[int]] = {
            i: set() for i in range(n)
        }
        index_to_k[1] = set([1])
        for i in range(1, n):
            for k in index_to_k[i]:
                for jump in [k - 1, k, k + 1]:
                    next_stone = stones[i] + jump
                    if next_stone == stones[-1]:
                        return True
                    if next_stone in stone_to_index:
                        index = stone_to_index[next_stone]
                        if index != i:
                            index_to_k[index].add(jump)
        return False
