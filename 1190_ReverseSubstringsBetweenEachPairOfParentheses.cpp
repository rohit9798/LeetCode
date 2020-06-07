You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
Example 4:

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"



class Solution {
public:
    void reverse(string &s1, int i, int j)
    {
        while(i < j)
        {
            if(s1[i] == '(' || s1[i] == ')')
                i++;
            else if(s1[j] == '(' || s1[j] == ')')
                j--;
            char temp = s1[i];
            s1[i] = s1[j];
            s1[j] = temp;
            i++;
            j--;
        }
    }
    string reverseParentheses(string s) {
        
        string s1 = s;
        stack<pair<char,int>> st;
        string temp = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                st.push({'(', i});
            else if(s[i] == ')')
            {
                reverse(s1, st.top().second, i);
                st.pop();
            }
        }
        string result = "";
        for(int i = 0; i < s1.length(); i++)
            if(s1[i] != '(' && s1[i] != ')')
                result = result + s1[i];
        return result;
    }
};
