class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(char c : s){
            if (c == '[' || c == '{' || c == '('){
                q.push(c);
            }
            else if(c == ']'){
                if(!q.empty() &&q.top() == '['){
                    q.pop();
                }
                else{
                    return false;
                }  
            }
            else if(c == '}'){
                if(!q.empty() &&q.top() == '{'){
                    q.pop();
                }
                else{
                    return false;
                }  
            }
            else if(c == ')'){
                if(!q.empty() &&q.top() == '('){
                    q.pop();
                }
                else{
                    return false;
                }  
            }
        }
        if(q.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
