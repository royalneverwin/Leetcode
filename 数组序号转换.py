class Solution:
    def First(self, a):
        return a[0]

    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not len(arr): # 特判
            return arr
        tmp = [[arr[i], i] for i in range(0, len(arr))]
        tmp.sort(key=self.First)
        prev = tmp[0][0]
        idx = 1
        for i in range(len(tmp)):
            if tmp[i][0] == prev:
                arr[tmp[i][1]] = idx
            else:
                idx += 1
                arr[tmp[i][1]] = idx
                prev = tmp[i][0]
        return arr
