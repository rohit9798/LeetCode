Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % 2 == 1)
            return false;
        int target = sum / 2;
        bool dp[nums.size()][target + 1];
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j <= target; j++)
                dp[i][j] = false;
        if(nums[0] <= target)
            dp[0][nums[0]] = true;
        for(int i = 0; i < nums.size(); i++)
            dp[i][0] = true;
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 1; j <= target; j++)
            {
                if(j < nums[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
        }
        return dp[nums.size() - 1][target];
    }
};
