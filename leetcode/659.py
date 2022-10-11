class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        tail_to_lens: Dict[int, Dict[int, int]] = {}
        for num in nums:
            if num not in tail_to_lens:
                tail_to_lens[num] = {}
            if num-1 not in tail_to_lens or len(tail_to_lens[num-1]) == 0:
                if 1 not in tail_to_lens[num]:
                    tail_to_lens[num][1] = 0
                tail_to_lens[num][1] += 1
            else:
                for i in [1, 2, 3]:
                    if i in tail_to_lens[num-1]:
                        tail_to_lens[num-1][i] -= 1
                        if tail_to_lens[num-1][i] == 0:
                            del tail_to_lens[num-1][i]
                        if i == 3:
                            if i not in tail_to_lens[num]:
                                tail_to_lens[num][i] = 0
                            tail_to_lens[num][i] += 1
                        else:
                            if i+1 not in tail_to_lens[num]:
                                tail_to_lens[num][i+1] = 0
                            tail_to_lens[num][i+1] += 1
                        break
        for tail in tail_to_lens:
            for i in [1, 2]:
                if i in tail_to_lens[tail]:
                    return False
        return True
