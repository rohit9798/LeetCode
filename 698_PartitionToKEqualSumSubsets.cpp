Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.




class Solution {
public:
    bool func(vector<int> &nums, vector<bool> &visited, int k, int target, int current, int index)
    {
        if(k == 0)
            return true;
        if(current == target)
            return func(nums, visited, k - 1, target, 0, 0);
        else
        {
            for(int i = index; i < nums.size(); i++)
            {
                if(!visited[i] && current + nums[i] <= target)
                {
                    visited[i] = true;
                    if(func(nums, visited, k, target, current + nums[i], i))
                        return true;
                    visited[i] = false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int total_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            total_sum += nums[i];
        }
        if(total_sum % k != 0)
            return false;
        int sum = total_sum / k;
        vector<bool> visited(nums.size(), false);
        return func(nums, visited, k, sum, 0, 0);
    }
};
