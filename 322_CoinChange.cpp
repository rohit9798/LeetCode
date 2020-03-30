You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int arr[amount + 1];
        for(int i = 0; i <= amount; i++)
        {
            arr[i] = -1;
        }
        arr[0] = 0;
        for(int i = 0; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                int index = i - coins[j];
                if(index >= 0)
                {
                    if(arr[index] != -1)
                    {
                        if(arr[index] + 1 < arr[i] || arr[i] == -1)
                            arr[i] = arr[index] + 1;
                    }
                }
            }
        }
        return arr[amount];
    }
};
