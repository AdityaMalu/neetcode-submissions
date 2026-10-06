# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        dict1 = {}
        que = []

        if root == None:
            return []
        que.append([root,0])
        while(len(que) != 0):
            top = que.pop(0)
            lvl = top[1]
            currnode = top[0]
            try:
                dict1[lvl].append(currnode.val)
            except:
                dict1[lvl] = [currnode.val]
            if(currnode.left):
                que.append([currnode.left,lvl+1])
            if(currnode.right):
                que.append([currnode.right,lvl+1])
        
        for i in dict1.values():
            ans.append(i)
        
        return ans
