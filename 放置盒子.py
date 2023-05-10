class Solution:
    def minimumBoxes(self, n: int) -> int:
        # 贪心
        # 3 6 10
        # 1 3 6
        #   1 3
        #     1
        # ...
        # summery: 1->1 2->2 3,4->3 5->4 6->5 7,8,9,10->6 11->7 12->8 13->9 14,15,...,20->10
        # 3最多+1 6最多+1+3 10最多+1+3+6 15最多+1+3+6+10 以此类推

        # g(i) = i(i+1)(i+2)/6 找到最小的i使得g(i) > n
        def g(x):
            return x*(x+1)*(x+2)//6
        i = int((6*n)**(1/3))
        if g(i) <= n:
            i += 1

        # 再求解剩下的部分
        # j^2+j-2n >= 0
        left = n-g(i-1)
        j = int(((8*left+1)**0.5-1)/2)
        if j**2+j < 2*left:
            j += 1

        return i*(i-1)//2+j





        