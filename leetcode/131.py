class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def is_palin(ss: str) -> bool:
            l, r = 0, len(ss)-1
            while l < r:
                if ss[l] != ss[r]:
                    return False
                l, r = l+1, r-1
            return True

        def check(tokens: List[str]) -> bool:
            return all([is_palin(ss) for ss in tokens])

        ans: List[List[str]] = []
        for spec in range((1 << (len(s)-1))):
            buf: List[str] = [s[:1]]
            for i in range(len(s)-1):
                if (1 << i) & spec:
                    buf.append(s[i+1:i+2])
                else:
                    buf[-1] += s[i+1]
            if check(buf):
                ans.append(buf)
        return ans
