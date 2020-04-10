Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.



class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n1 = word1.length();
        int n2 = word2.length();
        int dp[word1.length() + 1][word2.length() + 1];
        
        for(int i = 0; i <= word1.length(); i++)
        {
            for(int j = 0; j <= word2.length(); j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if(word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout<<dp[n1][n2];
        int sum = n1 + n2 - 2 * dp[n1][n2];
        return sum;
    }
};
