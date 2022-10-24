class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = 0
        while True:
            if len(students) == 0:
                return 0
            if students[0] == sandwiches[0]:
                students = students[1:]
                sandwiches = sandwiches[1:]
                cnt = 0
            else:
                students = students[1:]+students[0:1]
                cnt += 1
                if cnt == len(students):
                    return cnt
