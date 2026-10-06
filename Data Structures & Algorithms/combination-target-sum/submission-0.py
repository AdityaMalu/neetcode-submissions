class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []

        def recurr(ind, target, arr):
            if target == 0:
                ans.append(arr[:])  
                return
            if target < 0 or ind >= len(nums):
                return

            arr.append(nums[ind])
            recurr(ind, target - nums[ind], arr)
            arr.pop() 

            recurr(ind + 1, target, arr)

        recurr(0, target, [])
        return ans
