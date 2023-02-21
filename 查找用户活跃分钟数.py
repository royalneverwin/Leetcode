class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        my_dict = {}
        for log in logs:
            if log[0] not in my_dict:
                my_dict[log[0]] = set()
                my_dict[log[0]].add(log[1])
            else:
                my_dict[log[0]].add(log[1])

        res = [0 for i in range(k)]
        for key, val in my_dict.items():
            res[len(val)-1] += 1

        return res
