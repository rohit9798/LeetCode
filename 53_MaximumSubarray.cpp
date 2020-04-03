Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum[nums.size()];
        int maximum = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            sum[i] = nums[i];
        }
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < sum[i - 1] + nums[i])
                sum[i] = sum[i - 1] + nums[i];
            if(maximum < sum[i])
                maximum = sum[i];
        }
        return maximum;
    }
};
