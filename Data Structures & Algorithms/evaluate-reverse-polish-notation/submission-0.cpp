class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string token : tokens) {

            if (token != "+" && token != "-" &&
                token != "*" && token != "/") {

                stk.push(stoi(token));
            }

            else {
                int first = stk.top();
                stk.pop();

                int second = stk.top();
                stk.pop();

                if (token == "+") {
                    stk.push(second + first);
                }
                else if (token == "-") {
                    stk.push(second - first);
                }
                else if (token == "*") {
                    stk.push(second * first);
                }
                else {
                    stk.push(second / first);
                }
            }
        }

        return stk.top();
    }
};