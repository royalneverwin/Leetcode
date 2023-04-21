class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        a_month1 = int(arriveAlice[:2])
        a_day1 = int(arriveAlice[3:])
        a_month2 = int(leaveAlice[:2])
        a_day2 = int(leaveAlice[3:])

        day_per_month = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        a_begin = 0
        for i in range(1, a_month1):
            a_begin += day_per_month[i]
        a_begin += a_day1

        a_end = 0
        for i in range(1, a_month2):
            a_end += day_per_month[i]
        a_end += a_day2

        b_month1 = int(arriveBob[:2])
        b_day1 = int(arriveBob[3:])
        b_month2 = int(leaveBob[:2])
        b_day2 = int(leaveBob[3:])

        b_begin = 0
        for i in range(1, b_month1):
            b_begin += day_per_month[i]
        b_begin += b_day1

        b_end = 0
        for i in range(1, b_month2):
            b_end += day_per_month[i]
        b_end += b_day2

        res = 0
        for i in range(min(a_begin, b_begin), max(a_end, b_end)+1):
            if i >= a_begin and i >= b_begin and i <= a_end and i <= b_end:
                res += 1

        return res



