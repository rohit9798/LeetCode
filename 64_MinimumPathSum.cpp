Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        int dp[r + 1][c + 1];
        dp[1][1] = grid[0][0];
        for(int i = 0; i <= r; i++)
        {
            for(int j = 0; j <= c; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = INT_MAX;
                else if(i != 1 || j != 1)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }    
            }
        }
        return dp[r][c];
    }
};
