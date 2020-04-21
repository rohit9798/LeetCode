Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false



class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length() - 1;
        while(i < j)
        {
            while(i < s.length() && !isalnum(s[i]))
                i++;
            while(j >= 0 && !isalnum(s[j]))
                j--;
            if(i == s.length() || j < 0)
                return true;
            if(tolower(s[i]) == tolower(s[j]))
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
