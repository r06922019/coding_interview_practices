class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:

        def transpose(grid: list[list[int]]) -> list[list[int]]:
            n: int = len(grid)
            grid_t: list[list[int]] = [[0] * n for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    grid_t[j][i] = grid[i][j]
            return grid_t

        grid_t = transpose(grid)

        val_counter: dict[tuple[int], int] = {}
        for val in grid:
            val_tuple = tuple(val)
            if val_tuple not in val_counter:
                val_counter[val_tuple] = 0
            val_counter[val_tuple] += 1

        cnt: int = 0
        for i, val in enumerate(grid_t):
            val_tuple = tuple(val)
            if val_tuple in val_counter:
                cnt += val_counter[val_tuple]
        return cnt
