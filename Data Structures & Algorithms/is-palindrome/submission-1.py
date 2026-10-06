class Solution:
    def isPalindrome(self, s: str) -> bool:
        clrstr = ""
        for i in s:
            if i.isalnum():
                clrstr += i.lower()        
        i = 0
        j = len(clrstr)-1
        while(i <= j):
            if clrstr[i] == clrstr[j]:
                i+=1
                j-=1
            else:
                return False
        return True