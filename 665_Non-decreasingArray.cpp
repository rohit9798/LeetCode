Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.



class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int cnt = 0;                                                         
        for(int i = 1; i < nums.size() && cnt<=1 ; i++)
        {
            if(nums[i-1] > nums[i])
            {
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];          
                else 
                    nums[i] = nums[i-1];                                     
            }
        }
        return cnt<=1;
    } 
};
