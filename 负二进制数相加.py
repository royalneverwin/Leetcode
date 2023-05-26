class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res_list = []
        n1, n2 = len(arr1), len(arr2)
        idx1, idx2 = n1-1, n2-1
        nxt1, nxt2 = 0, 0 # 在-2进制中，1+1 = 110 会进两位
        while idx1 >= 0 and idx2 >= 0:
            cnt_1 = nxt1+arr1[idx1]+arr2[idx2]
            nxt1 = nxt2
            nxt2 = 0
            nxt1 += cnt_1 // 2
            nxt2 += cnt_1 // 2
            cnt_1 %= 2
            res_list.insert(0, cnt_1)
            idx1, idx2 = idx1-1, idx2-1
        while idx1 >= 0:
            cnt_1 = nxt1+arr1[idx1]
            nxt1 = nxt2
            nxt2 = 0
            nxt1 += cnt_1 // 2
            nxt2 += cnt_1 // 2
            cnt_1 %= 2
            res_list.insert(0, cnt_1)
            idx1 = idx1-1

        while idx2 >= 0:
            cnt_1 = nxt1+arr2[idx2]
            nxt1 = nxt2
            nxt2 = 0
            nxt1 += cnt_1 // 2
            nxt2 += cnt_1 // 2
            cnt_1 %= 2
            res_list.insert(0, cnt_1)
            idx2 = idx2-1

        # print(nxt1, nxt2)

        while nxt1 > 0 or nxt2 > 0:
            while nxt1 >= 2 and nxt2 > 0: # 可以抵消
                nxt1 -= 2
                nxt2 -= 1
            cnt_1 = nxt1
            nxt1 = nxt2
            nxt2 = 0
            nxt1 += cnt_1 // 2
            nxt2 += cnt_1 // 2
            cnt_1 %= 2
            res_list.insert(0, cnt_1)

        # 去掉前导0
        idx = 0
        while idx < len(res_list) and res_list[idx] == 0:
            idx += 1

        if idx == len(res_list):
            return [0]
        else:
            return res_list[idx:]

