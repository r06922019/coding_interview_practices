class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda el: (el[1], el[0]))
        ans = []
        for person in people:
            h, k = person
            cur_k = 0
            for p in ans:
                if p[0] >= h:
                    cur_k += 1
            index = len(ans)
            while cur_k > k:
                if ans[index-1][0] >= h:
                    cur_k -= 1
                index -= 1
            ans.insert(index, person)
        return ans
