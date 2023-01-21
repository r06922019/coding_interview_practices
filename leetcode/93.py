class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans: List[str] = []
        ss = set([str(x) for x in range(256)])

        def valid(ip: str) -> bool:
            parts = ip.split('.')
            if len(parts) != 4:
                return False
            return all([x in ss for x in parts])

        def helper(i: int, dots: int, buf: str):
            if i == len(s) and dots == 0:
                print("buf:%s" % (buf))
                if valid(buf):
                    ans.append(buf)
                return
            if i < len(s):
                helper(i+1, dots, buf+s[i])
            if dots > 0:
                helper(i, dots-1, buf+'.')
            return
        helper(0, 3, "")
        return ans
