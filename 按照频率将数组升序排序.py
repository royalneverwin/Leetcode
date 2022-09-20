class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cnt = {}
        lst = {}
        for i in nums:
            if i not in cnt:
                cnt[i] = 1
            else:
                cnt[i] += 1

        for item in cnt.items():
            if item[1] not in lst:
                lst[item[1]] = [item[0]]
            else:
                lst[item[1]].append(item[0])

        freq_lst = list(lst.keys())
        freq_lst.sort()

        res = []
        for i in freq_lst:
            num_lst = lst[i]
            num_lst.sort(reverse=True)
            for num in num_lst:
                for _ in range(i):
                    res.append(num)

        return res

        