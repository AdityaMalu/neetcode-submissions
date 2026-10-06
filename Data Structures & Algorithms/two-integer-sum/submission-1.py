class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for i in range(len(nums)):
            diff = target-nums[i]
            if diff in hash_map:
                return [min(i,hash_map[diff]) , max(i,hash_map[diff])]
            hash_map[nums[i]] = i
        return []
