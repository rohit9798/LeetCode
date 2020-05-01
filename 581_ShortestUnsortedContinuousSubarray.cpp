Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.



class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int start = 0, end = nums.size() - 1;
        for(start = 0; start < end; start++)
        {
            if(nums[start] > nums[start + 1])
                break;
        }
        if(start == end)
            return 0;
        for(end = nums.size() - 1; end > 0; end--)
        {
            if(nums[end - 1] > nums[end])
                break;
        } 
        int minimum = nums[start];
        int maximum = nums[start];
        for(int i = start + 1; i <= end; i++)
        {
            if(minimum > nums[i])
                minimum = nums[i];
            if(maximum < nums[i])
                maximum = nums[i];
        }
        for(int i = 0; i < start; i++)
        {
            if(nums[i] > minimum)
            {
                start = i;
                break;
            }
        }
        for(int i = nums.size() - 1; i >= end; i--)
        {
            if(maximum > nums[i])
            {
                end = i;
                break;
            }
        }
        return end - start + 1;
    }
};
