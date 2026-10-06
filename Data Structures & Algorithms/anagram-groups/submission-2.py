class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # ans = []
        # hash_map = {}
        # for i in strs:
        #     sorte =  tuple(sorted(i))
        #     if sorte in hash_map:
        #         hash_map[sorte].append(i)
        #     else:
        #         hash_map[sorte] = [i]
        
        # for i in hash_map.values():
        #     ans.append(i)
        
        # return ans

        ans = []

        hash_map = {}
        
        for i in strs:
            temp = [0]*26
            for j in i:
                temp[ord(j) - ord("a")] += 1

            key = tuple(temp)
            if key in hash_map:
                hash_map[key].append(i)
            else:
                hash_map[key] = [i]
        
        for i in hash_map.values():
            ans.append(i)
        
        return ans

