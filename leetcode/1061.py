class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        groups: Dict[str, str] = {}

        def get_group(a: str) -> str:
            if groups[a] != a:
                groups[a] = get_group(groups[a])
            return groups[a]

        def merge(a: str, b: str):
            a, b = get_group(a), get_group(b)
            groups[a] = groups[b] = min(a, b)

        for i in range(26):
            c = chr(ord('a')+i)
            groups[c] = c

        for i in range(len(s1)):
            merge(s1[i], s2[i])

        return "".join([get_group(c) for c in baseStr])
