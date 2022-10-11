class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        i, m, ans = 0, len(trainers), 0
        for p in players:
            while i < m and trainers[i] < p:
                i += 1
            if i == m:
                break
            ans += 1
            i += 1
        return ans
