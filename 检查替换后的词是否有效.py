class Solution:
    def isValid(self, s: str) -> bool:
        n = len(s)
        st = deque()
        for i in range(n):
            if s[i] == 'a':
                st.append('a')
            elif s[i] == 'b':
                st.append('b')
            else:
                if len(st) >= 2 and st[-1] == 'b' and st[-2] == 'a':
                    st.pop()
                    st.pop()
                else:
                    return False

        if st:
            return False
        return True