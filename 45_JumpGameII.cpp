Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
    
   
   

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int currFarthest = 0, currEnd = 0, maximum = 0, steps = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            currFarthest = max(currFarthest, nums[i] + i);
            if(i == currEnd)
            {
                steps++;
                currEnd = currFarthest;
            }
        }
        return steps;
    }
};
