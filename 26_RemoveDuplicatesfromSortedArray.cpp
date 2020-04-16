Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int j = 1;
        if(nums.size() == 0)
            return 0;
        while(j < nums.size())
        {
            while(j < nums.size() && nums[start] == nums[j])
                j++;
            if(j < nums.size() && start + 1 < nums.size())
            {
                int temp = nums[start + 1];
                nums[start + 1] = nums[j];
                nums[j] = temp;
                start++;
            }
            j++;
            
        }
        
        return start + 1;
    }
};
