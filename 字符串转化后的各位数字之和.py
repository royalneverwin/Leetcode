class Solution:
    def getLucky(self, s: str, k: int) -> int:
        cur = s
        my_sum = ''
        for i in cur:
            my_sum += str(ord(i) - ord('a') + 1)
        cur = my_sum

        for i in range(k):
            my_sum = 0
            for j in cur:
                my_sum += int(j)
            if my_sum < 10:
                return my_sum
            cur = str(my_sum)

        return my_sum


