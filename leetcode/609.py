class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = {}
        for p in paths:
            tokens = p.split()
            dir_name = tokens[0]
            for token in tokens[1:]:
                f, content = token.split('(')
                content = content[:-1]
                if content not in d:
                    d[content] = []
                d[content].append(dir_name+'/'+f)

        return [v for v in d.values() if len(v) >= 2]
