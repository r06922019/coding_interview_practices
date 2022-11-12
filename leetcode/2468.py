class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        def achievable(parts: int):
            size = 0
            for i in range(1, parts+1):
                suffix = "<%d/%d>" % (i, parts)
                size += max(0, limit - len(suffix))
                # print("suffix = %s, size = %d" % (suffix, size))
            return size >= len(message)

        l, r = 1, min(len(message), 9999)
        if not achievable(r):
            return []

        while l < r:
            mid = (l+r)//2
            if not achievable(mid):
                l = mid + 1
            else:
                r = mid

        index, parts, ret = 0, l, []
        for i in range(1, parts+1):
            suffix = "<%d/%d>" % (i, parts)
            size = max(limit - len(suffix), 0)
            ret.append(message[index:index+size] + suffix)
            index += size
        return ret
