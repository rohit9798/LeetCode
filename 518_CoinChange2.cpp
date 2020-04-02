You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1



int change(int t, vector<int>& coins) {
      
        int dp[t + 1];
        for(int i = 0; i <= t; i++)
            dp[i] = 0;
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i)
            for (int j = coins[i]; j <= t; ++j) 
                dp[j] += dp[j - coins[i]];
        return dp[t];
   }
