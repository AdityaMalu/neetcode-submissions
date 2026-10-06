class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hash_table = {}
        for i in nums:
            try:
                if hash_table[i] == 1:
                    return True
            except:
                hash_table[i] = 1
        return False
         