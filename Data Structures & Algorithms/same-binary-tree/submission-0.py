# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def preorder(self,root,arr):
        if root == None:
            arr.append("null")
            return
        
        arr.append(root.val)
        self.preorder(root.left,arr)
        self.preorder(root.right,arr)

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        arr1 = []
        arr2 = []
        self.preorder(p,arr1)
        self.preorder(q,arr2)
        return arr1 == arr2
