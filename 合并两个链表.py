# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        idx = 0
        cur = list1
        pre = None
        nxt = None
        while idx < b:
            if idx == a-1:
                pre = cur

            idx += 1
            cur = cur.next

        nxt = cur.next
        if pre == None:
            res = list2
        else:
            res = list1
            pre.next = list2
        cur = list2
        while cur.next != None:
            cur = cur.next

        cur.next = nxt
        return list1

            