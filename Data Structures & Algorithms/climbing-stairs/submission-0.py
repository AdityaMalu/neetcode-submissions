class Solution:
    def recurr(self,n,dp):
        if n == 0:
            return 1
        
        if n < 0:
            return 0
        
        if dp[n] != -1:
            return dp[n]
        
        one = self.recurr(n-1,dp)
        two = self.recurr(n-2,dp)

        dp[n] = one + two

        return dp[n]

    def climbStairs(self, n: int) -> int:
        dp = [-1]*(n+1)
        return self.recurr(n,dp)
        