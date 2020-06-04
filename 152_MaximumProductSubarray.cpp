Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int prefix = 1, suffix = 1;
        int result = INT_MIN, n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(prefix == 0)
                prefix = 1;
            if(suffix == 0)
                suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n - 1 - i];
            result = max(result, max(prefix, suffix));
        }
        return result;
    }
};
