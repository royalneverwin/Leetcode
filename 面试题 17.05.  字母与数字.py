class Solution:
    def findLongestSubarray(self, array: List[str]) -> List[str]:
        n = len(array)
        presum_n = [0 for i in range(n+1)]
        presum_a = [0 for i in range(n+1)]
        for i in range(n):
            if array[i].isalpha():
                presum_a[i+1] = presum_a[i] + 1
                presum_n[i+1] = presum_n[i]
            else:
                presum_n[i+1] = presum_n[i] + 1
                presum_a[i+1] = presum_a[i]

        sub_dict = {0: [-1]}
        for i in range(n):
            sub = presum_n[i+1]-presum_a[i+1]
            if sub in sub_dict:
                sub_dict[sub].append(i)
            else:
                sub_dict[sub] = [i]

        for key in sub_dict:
            sub_dict[key].sort()

        res = 0
        res1, res2 = 0, 0
        for key, val in sub_dict.items():
            if val[-1]-val[0] > res:
                res1, res2, res = val[0], val[-1], val[-1]-val[0]

        return array[res1+1:res2+1]

        return res