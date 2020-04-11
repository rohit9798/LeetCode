Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.



class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1 = str1.length();
        int n2 = str2.length();
        string dp[n2 + 1][n1 + 1];
        string temp(1,str1[0]);
        for(int i = 1; i <= n1; i++)
        {
            dp[0][i] = temp;
            temp = temp + str1[i];
        }
        string temp1(1,str2[0]);
        for(int j = 1; j <= n2; j++)
        {
            dp[j][0] = temp1;
            temp1 += str2[j];
        }
        for(int i = 1; i <= n2; i++)
        {
            for(int j = 1; j <= n1; j++)
            {
                if(str2[i - 1] == str1[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + str2[i - 1];
                else
                {
                    if(dp[i - 1][j].length() >= dp[i][j - 1].length())
                    {
                        dp[i][j] = dp[i][j - 1] + str1[j - 1];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + str2[i - 1];
                    }
                }
            }
        }
        return dp[n2][n1];
     }
 };
