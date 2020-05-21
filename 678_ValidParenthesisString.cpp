Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True



class Solution {
public:
    bool checkValidString(string s) {
        
        int openmin = 0, openmax = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                openmin++;
                openmax++;
            }
            if(s[i] == '*')
            {
                openmax++;
                openmin--;
            }
            if(s[i] == ')')
            {
                openmin--;
                openmax--;
            }
            if(openmax < 0)
                break;
            openmin = max(0, openmin);
        }
        return openmin == 0;
        
    }
};
