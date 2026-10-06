class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i = 0
        j = len(heights)-1
        ans = -1
        while(i < j):
            lheight = heights[i]
            rheight = heights[j]
            area = (j - i)*min(lheight,rheight)
            ans = max(area,ans)
            if(lheight < rheight):
                i+=1
            else:
                j-=1
        return ans
        