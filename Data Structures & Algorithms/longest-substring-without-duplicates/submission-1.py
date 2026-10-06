class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        unique = set()
        ans = 0
        i = 0
        j = 0
        while(j < len(s)):
            if s[j] in unique:
                unique.remove(s[i])
                i+=1
            else:
                unique.add(s[j])
                ans = max(ans,len(unique))
                j+=1
        return ans
            