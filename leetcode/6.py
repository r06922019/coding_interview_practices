class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        rows = [""] * numRows
        index, d = 0, 1
        for c in s:
            rows[index] += c
            index += d
            if index == -1:
                index, d = 1, 1
            elif index == numRows:
                index, d = numRows-2, -1
        return "".join(rows)
