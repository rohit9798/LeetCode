Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
Example 4:

Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4
Example 5:

Input: nums = [0,0,0]
Output: 0



class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                prefix[i] = 0;
            else if(i > 0)
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = 1;
        }
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] == 0)
                suffix[i] = 0;
            else if(i + 1 < nums.size())
                suffix[i] = suffix[i + 1] + 1;
            else
                suffix[i] = 1;
        }
        for(int i = 0; i < nums.size(); i ++)
        {
            cout<<suffix[i]<<" ";
        }
        int maximum = INT_MIN;
        if(suffix[0] == nums.size())
            return nums.size() - 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0 && nums[i] == 0)
                maximum = max(maximum, suffix[i + 1]);
            else if(i == nums.size() - 1 && nums[i] == 0)
                maximum = max(maximum, prefix[i - 1]);
            else if(nums[i] == 0)
            {
                maximum = max(maximum, prefix[i - 1] + suffix[i + 1]);
            }
        }
        return maximum;
    }
};
