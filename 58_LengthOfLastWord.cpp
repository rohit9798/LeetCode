Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5



class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count = 0;
        if(s.size() == 0)
            return s.size();
        while(s.size() > 0 && s[s.size() - 1] == ' ')
            s.pop_back();
        if(s.size() == 0)
            return 0;
        for(int i = s.size() - 1; i >= 0 && s[i] != ' '; i--)
        {
            count++;
        }
        return count;
    }
};
