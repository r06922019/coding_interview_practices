class WordFilter:

    def __init__(self, words: List[str]):
        self.d = {}
        for i, word in enumerate(words):
            for l in range(1, min(10, len(word))+1):
                prefix = word[:l]
                for r in range(1, min(10, len(word))+1):
                    suffix = word[-r:]
                    key = (prefix, suffix)
                    if key not in self.d:
                        self.d[key] = []
                    self.d[key].append(i)

    def f(self, prefix: str, suffix: str) -> int:
        key = (prefix, suffix)
        return self.d[key][-1] if key in self.d else -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)

# ["WordFilter","f","f","f","f","f","f","f","f","f","f"]
# [[["cabaabaaaa","ccbcababac","bacaabccba","bcbbcbacaa","abcaccbcaa","accabaccaa","cabcbbbcca","ababccabcb","caccbbcbab","bccbacbcba"]],["bccbacbcba","a"],["ab","abcaccbcaa"],["a","aa"],["cabaaba","abaaaa"],["cacc","accbbcbab"],["ccbcab","bac"],["bac","cba"],["ac","accabaccaa"],["bcbb","aa"],["ccbca","cbcababac"]]
