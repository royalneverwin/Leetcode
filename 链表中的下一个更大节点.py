# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        st = []
        ls = []
        while head:
            ls.append(head.val)
            head = head.next
        n = len(ls)
        ans = [0 for i in range(n)]
        st.append(ls[n-1])
        for i in range(n-2, -1, -1):
            while st != [] and ls[i] >= st[0]:
                st.pop(0)
            if st != []:
                ans[i] = st[0]
            st.insert(0, ls[i])

        return ans

