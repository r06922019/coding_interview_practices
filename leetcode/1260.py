class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        k = k % (m*n)
        if k == 0:
            return grid
        f = [el for l in grid for el in l]
        f = f[::-1]
        f[:k] = f[:k][::-1]
        f[k:] = f[k:][::-1]
        return [ f[i:i+n] for i in range(0, len(f), n) ]
