# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if head:
            preslow = None
            slow = head
            fast = head
            while True:
                if fast.next:
                    fast = fast.next
                else:
                    break
                if fast.next:
                    fast = fast.next
                    preslow = slow
                    slow = slow.next
                else:
                    break
            if preslow:
                preslow.next = None
                return TreeNode(slow.val, self.sortedListToBST(head), self.sortedListToBST(slow.next))
            else:
                return TreeNode(slow.val, None, self.sortedListToBST(slow.next))
        else:
            return None