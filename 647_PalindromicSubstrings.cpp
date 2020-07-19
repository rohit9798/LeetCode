Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".



class Solution {
public:
    void isPalindrome(string s, int i, int j, int &count)
    {
        while(i >= 0 && j < s.length() && s[i] == s[j])
        {
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            isPalindrome(s, i, i, count);
            isPalindrome(s, i, i + 1, count);
        }
        return count;
    }
};
