class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        # 种类并查集 敌人的敌人就是朋友
        # 使用两倍大小的数组
        arr = [i for i in range(2*n+1)]
        def parent(i):
            nonlocal arr
            if arr[i] == i:
                return arr[i]
            else:
                arr[i] = parent(arr[i])
                return arr[i]

        def merge(a, b):
            nonlocal arr
            p1 = parent(a)
            p2 = parent(b)
            arr[p2] = p1

        for dislike in dislikes:
            merge(dislike[0], n+dislike[1])
            merge(dislike[1], n+dislike[0])

        for i in range(1, 2*n+1):
            arr[i] = parent(arr[i])

        for i in range(1, n+1):
            if arr[i] == arr[n+i]:
                return False

        return True
            