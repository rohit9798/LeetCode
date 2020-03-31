iven two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int L[text1.length() + 1][text2.length() + 1];
        
        for(int i = 0; i <= text1.length(); i++)
        {
            for(int j = 0; j <= text2.length(); j++)
            {
                if(i == 0 || j == 0)
                    L[i][j] = 0;
                else
                {
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                    if(text1[i - 1] == text2[j - 1])
                    {
                        L[i][j] = max(L[i][j], L[i - 1][j - 1] + 1);
                    }
                }
            }
        }
        return L[text1.length()][text2.length()]; 
    }
};
