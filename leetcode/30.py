class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        w_cnt = len(words)
        w_l = len(words[0])
        w2i = {w: i for i, w in enumerate(set(words))}
        def to_index(_s): return w2i[_s] if _s in w2i else -1
        s_i = [[i, to_index(s[i:i+w_l])] for i in range(len(s))]
        target = Counter([w2i[w] for w in words])

        def find_in_list(l):
            ret = []
            cur = {}
            for i in range(len(l)):
                if i >= w_cnt:
                    prev_num = l[i-w_cnt][1]
                    cur[prev_num] -= 1
                    if cur[prev_num] == 0:
                        del cur[prev_num]
                x = l[i][1]
                if x not in cur:
                    cur[x] = 0
                cur[x] += 1
                if cur == target:
                    ret.append(l[i-w_cnt+1][0])
            return ret

        ans = []
        for start in range(w_l):
            index_nums = s_i[start::w_l]
            ans.extend(find_in_list(index_nums))

        return ans
