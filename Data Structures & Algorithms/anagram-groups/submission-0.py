class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        hash_map = {}
        for i in strs:
            sorte =  tuple(sorted(i))
            if sorte in hash_map:
                hash_map[sorte].append(i)
            else:
                hash_map[sorte] = [i]
        
        for i in hash_map.values():
            ans.append(i)
        
        return ans