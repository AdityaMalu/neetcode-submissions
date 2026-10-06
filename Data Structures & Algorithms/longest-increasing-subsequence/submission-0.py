class Solution:
    def recurr(self,ind,nums,prev,dp):
        if ind == len(nums):
            return 0

        if dp[ind][prev+1] != -1:
            return dp[ind][prev+1]
        
        not_pick = self.recurr(ind+1,nums,prev,dp)
        pick = 0
        if nums[prev] < nums[ind] or prev == -1:
            pick = 1 + self.recurr(ind+1,nums,ind,dp)

        dp[ind][prev+1] = max(pick,not_pick)
        
        return max(pick,not_pick)

    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [[-1 for i in range(len(nums)+1)] for _ in range(len(nums))]
        return self.recurr(0,nums,-1,dp)
        