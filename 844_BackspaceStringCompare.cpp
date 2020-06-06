Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        stack<int> s1, s2;
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] != '#')
                s1.push(S[i]);
            else if(!s1.empty())
                s1.pop();
        }
        for(int i = 0; i < T.length(); i++)
        {
            if(T[i] != '#')
                s2.push(T[i]);
            else if(!s2.empty())
                s2.pop();
        }
        return s1 == s2;
    }
};
