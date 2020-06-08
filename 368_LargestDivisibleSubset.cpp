Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]



class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> result;
        int n = nums.size();
        if(n == 0)
            return result;
        int dp[n], prev[n];
        sort(nums.begin(), nums.end());
        int position = 0, maximum = 1;
        
        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;
            prev[i] = i;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                        if(dp[i] > maximum)
                        {
                            maximum = dp[i];
                            position = i;
                        }
                    }
                }
            }
        }
        while(position != prev[position])
        {
            result.push_back(nums[position]);
            position = prev[position];
        }
        
        result.push_back(nums[position]);
        reverse(result.begin(), result.end());
        return result;
    }
};
