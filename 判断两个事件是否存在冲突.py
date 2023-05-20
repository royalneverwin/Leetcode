class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        start1 = int(event1[0][:2]) * 60 + int(event1[0][3:])
        end1 = int(event1[1][:2]) * 60 + int(event1[1][3:])
        start2 = int(event2[0][:2]) * 60 + int(event2[0][3:])
        end2 = int(event2[1][:2]) * 60 + int(event2[1][3:])

        if start1 >= start2 and start1 <= end2:
            return True
        if end1 >= start2 and end1 <= end2:
            return True
        if start2 >= start1 and start2 <= end1:
            return True
        if end2 >= start1 and end2 <= end1:
            return True
        return False