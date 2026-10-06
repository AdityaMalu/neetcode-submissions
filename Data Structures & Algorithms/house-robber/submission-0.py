class Solution:
    def recurr(self,nums,ind,dp):
        if ind >= len(nums):
            return 0
        
        if dp[ind] != -1:
            return dp[ind]

        rob = nums[ind] + self.recurr(nums,ind+2,dp)
        not_rob = self.recurr(nums,ind+1,dp)

        dp[ind] = max(rob,not_rob)

        return dp[ind]

    def rob(self, nums: List[int]) -> int:
        dp = [-1]*(len(nums) + 1)
        return self.recurr(nums,0,dp)
        