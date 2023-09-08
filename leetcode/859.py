class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if s == goal:
            return max(Counter(s).values()) > 1
        if len(s) != len(goal):
            return False
        diffs = []
        for a, b in zip(s, goal):
            if a != b:
                diffs.append([a, b])

        if len(diffs) == 2:
            return diffs[0][::-1] == diffs[1]

        return False
