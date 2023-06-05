class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        # 小的先合并 大的后合并
        # 单调栈
        st = []
        n = len(arr)
        res = 0
        for i in range(n):
            if st == [] or st[-1] > arr[i]: # 栈顶大于i 入栈
                st.append(arr[i])
            else: # 否则先合并再入栈
                while True:
                    tmp = st.pop(-1)
                    if st == []:
                        res += arr[i] * tmp
                        st.append(arr[i])
                        break
                    elif st[-1] > arr[i]:
                        res += arr[i] * tmp
                        st.append(arr[i])
                        break
                    else:
                        res += st[-1] * tmp

        while len(st) > 1:
            tmp1 = st.pop(-1)
            tmp2 = st.pop(-1)
            res += tmp1 * tmp2
            st.append(tmp2)

        return res
