Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.

 

Example 1:



Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:



Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
Example 3:

Input: nums = [1,1,1,1,1], k = 0
Output: true
Example 4:

Input: nums = [0,1,0,1], k = 1
Output: true
 

Constraints:

1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] is 0 or 1




class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int i = 0, j = 1;
        while(i < nums.size() && nums[i] != 1)
            i++;
        if(i == nums.size())
            return true;
        j = i;
        j++;
        while(j < nums.size())
        {
            while(j < nums.size() && nums[j] != 1)
                j++;
            if(j == nums.size())
                return true;
            if(j - i - 1 < k)
                return false;
            i = j;
            j++;
        }
        return true;
    }
};
