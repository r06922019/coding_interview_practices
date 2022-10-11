class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        def parseData(data: str):
            m, d = data.split("-")
            return int(m), int(d)

        def m2d2_is_bigger(m1, d1, m2, d2):
            return m1 < m2 or (m1 == m2 and d1 < d2)

        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        arriveAliceMonth, arriveAliceDay = parseData(arriveAlice)
        leaveAliceMonth, leaveAliceDay = parseData(leaveAlice)
        arriveBobMonth, arriveBobDay = parseData(arriveBob)
        leaveBobMonth, leaveBobDay = parseData(leaveBob)

        if m2d2_is_bigger(leaveAliceMonth, leaveAliceDay, arriveBobMonth, arriveBobDay):
            return 0
        if m2d2_is_bigger(leaveBobMonth, leaveBobDay, arriveAliceMonth, arriveAliceDay):
            return 0

        if m2d2_is_bigger(arriveAliceMonth, arriveAliceDay, arriveBobMonth, arriveBobDay):
            m1, d1 = arriveBobMonth, arriveBobDay
        else:
            m1, d1 = arriveAliceMonth, arriveAliceDay
        if m2d2_is_bigger(leaveAliceMonth, leaveAliceDay, leaveBobMonth, leaveBobDay):
            m2, d2 = leaveAliceMonth, leaveAliceDay
        else:
            m2, d2 = leaveBobMonth, leaveBobDay

        if m1 == m2:
            return d2-d1+1
        else:
            ans = d2 + days[m1-1] - d1 + 1
            m1 += 1
            while m1 < m2:
                ans += days[m1-1]
                m1 += 1
            return ans
