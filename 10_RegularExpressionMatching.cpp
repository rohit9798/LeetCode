Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false



class Solution {
public:
    bool isMatch(string A, string B) {
    
    int n1 = B.length();
    int n2 = A.length();
    int dp[n1 + 1][n2 + 1];
    dp[0][0] = 1;
    for(int i = 1; i <= n1; i++)
    {
        if(B[i - 1] == '*')
            dp[i][0] = dp[i - 2][0];
        else
            dp[i][0] = 0;
    }
    for(int i = 1; i <= n2; i++)
        dp[0][i] = 0;    
    
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(B[i - 1] == A[j - 1] || B[i - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(B[i - 1] == '*')
            {
                if(B[i - 2] == '.' || A[j - 1] == B[i - 2])
                {
                    dp[i][j] = dp[i - 2][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 2][j];
                }
            }
            else
                dp[i][j] = 0;
        }
    }
    /*for(int i = 0; i <= n1; i++)
    {
        for(int j = 0; j <= n2; j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    return dp[n1][n2];
}

};
