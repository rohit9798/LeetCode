Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23



class Solution {
public:
    int calculate(string s) {
        
        int number = 0, result = 0, sign = 1;
        stack<int> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                number = number * 10 + (s[i] - '0');
            }
            else if(s[i] == '+')
            {
                result += sign * number;
                sign = 1;
                number = 0;
            }
            else if(s[i] == '-')
            {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            else if(s[i] == '(')
            {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            }
            else if(s[i] == ')')
            {
                result += sign * number;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
                number = 0;
            }
        }
        return result + sign * number;
    }
};
