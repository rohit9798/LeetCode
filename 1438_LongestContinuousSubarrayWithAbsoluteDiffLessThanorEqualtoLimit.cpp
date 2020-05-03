Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9



class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int minimum = nums[0], maximum = nums[0];
        int length = 0, max_length = INT_MIN, start, pos = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            minimum = nums[i];
            maximum = nums[i];
            start = i;
            while((maximum - minimum) <= limit)
            {
                start++;
                length++;
                if(start == nums.size())
                    break;
                if(minimum >= nums[start])
                {
                    minimum = nums[start];
                }
                if(maximum < nums[start])
                    maximum = nums[start];
            }
            cout<<i << " ";
            if(max_length < length)
                max_length = length;
            length = 0;
            if(max_length > nums.size() / 2)
                return max_length;
        }
        return max_length;
    }
};
