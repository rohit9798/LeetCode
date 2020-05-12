You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.



class Solution {
public:
    int binary(vector<int> &nums, int low, int high)
    {
        if(low < high)
        {
            int mid = (low + high) / 2;
            if(mid < nums.size() - 1 && mid % 2 == 0 && nums[mid] == nums[mid + 1])
                return binary(nums, mid + 1, high);
            else if(mid > 0 && mid % 2 == 0 && nums[mid] == nums[mid - 1])
                return binary(nums, low, mid - 1);
            else if(mid > 0 && mid % 2 != 0 && nums[mid - 1] == nums[mid])
                return binary(nums, mid + 1, high);
            else if(mid < nums.size() - 1 && mid % 2 != 0 && nums[mid + 1] == nums[mid])
                return binary(nums, low, mid - 1);
            else
                return nums[mid];
        }
        return nums[low];
    }
    int singleNonDuplicate(vector<int>& nums) {
        
        return binary(nums, 0, nums.size() - 1);
        
    }
};
