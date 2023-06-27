class SnapshotArray:

    def __init__(self, length: int):
        self.snapshots = [[[0, 0]] for _ in range(length)]
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
        if self.snapshots[index][-1][0] != self.snap_id:
            self.snapshots[index].append([self.snap_id, 0])
        self.snapshots[index][-1][1] = val

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id-1

    def get(self, index: int, snap_id: int) -> int:
        if snap_id >= self.snapshots[index][-1][0]:
            return self.snapshots[index][-1][1]
        l, r = 0, len(self.snapshots[index])-1
        while l < r:
            mid = (l+r)//2
            if self.snapshots[index][mid][0] > snap_id:
                r = mid
            else:
                l = mid+1
        return self.snapshots[index][l-1][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
