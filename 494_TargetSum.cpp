You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.




class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        sort(nums.begin(), nums.end());
        int total_sum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                count++;
            else
                total_sum += nums[i];
        }
        if(total_sum < S || (S + total_sum) % 2 != 0)
            return 0;
        total_sum = (S + total_sum) / 2;
        int dp[nums.size()][total_sum + 1];
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j <= total_sum; j++)
                dp[i][j] = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            for(int j = 0; j <= total_sum; j++)
            {
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                {
                    if(nums[i] == j)
                        dp[i][j] = 1;
                }
                else
                {
                    if(j >= nums[i])
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size() - 1][total_sum] * pow(2, count);
    }
};
