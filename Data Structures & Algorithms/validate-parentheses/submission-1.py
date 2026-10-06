class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stk.append(i)
            elif i == ')':
                if len(stk)==0:
                    return False
                if stk[-1] == '(':
                    stk.pop(-1)
                else:
                    return False
            elif i == ']':
                if len(stk)==0:
                    return False
                if stk[-1] == '[':
                    stk.pop(-1)
                else:
                    return False
            elif i == '}':
                if len(stk)==0:
                    return False
                if stk[-1] == '{':
                    stk.pop(-1)
                else:
                    return False
        if len(stk) == 0:
            return True
        else:
            return False