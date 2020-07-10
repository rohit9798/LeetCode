Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.



class Solution {
public:
    int numSquares(int n) {
        
        int sqrtn = sqrt(n);
        int minimum = INT_MAX;
        int dp[sqrtn + 1][n + 1];
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
            dp[0][i] = i;
        for(int i = 1; i <= sqrtn; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= sqrtn; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i * i > j)
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    if(i * i == j)
                        dp[i][j] = 1;
                    else if(i * i < j)
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - i * i] + 1);
                }
            }
        }
        for(int i = 0; i <= sqrtn; i++)
            minimum = min(minimum, dp[i][n]);
        return minimum;
    }
};
