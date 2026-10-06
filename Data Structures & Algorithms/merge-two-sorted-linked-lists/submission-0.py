# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        one = list1
        two = list2
        dum = ListNode(-1)
        dum2 = dum

        while one and two:
            if one.val > two.val:
                dum.next = two
                two = two.next
            else:
                dum.next = one
                one = one.next
            dum = dum.next
            
        if one:
            dum.next = one
        else:
            dum.next = two

        return dum2.next
