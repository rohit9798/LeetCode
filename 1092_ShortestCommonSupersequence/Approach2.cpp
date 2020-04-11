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
        int dp[n1 + 1][n2 + 1];
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(j == 0)
                    dp[i][0] = i;
                else if(i == 0)
                    dp[0][j] = j;
                else
                {
                    if(str1[i - 1] == str2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        string result = "";
        int i = n1, j = n2;
        while(i > 0 && j > 0)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                result = result + str1[i - 1];
                i--; 
                j--;
            }
            else
            {
                if(dp[i][j - 1] < dp[i - 1][j])
                {
                    result += str2[j - 1];
                    j--;
                }
                else
                {
                    result += str1[i - 1];
                    i--;
                }
            }
        }
        while(i > 0)
        {
            result = result + str1[i - 1];
            i--;
        }
        while(j > 0)
        {
            result = result + str2[j - 1];
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
