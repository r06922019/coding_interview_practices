class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        ans, seen = -1, {}
        for index, card in enumerate(cards):
            if card in seen:
                cur_ans = index - seen[card] + 1
                if ans == -1 or ans > cur_ans:
                    ans = cur_ans
            seen[card] = index
        return ans
