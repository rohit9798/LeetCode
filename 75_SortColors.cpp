Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]



class Solution {
public:
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]);
                        break;
                case 1: mid++;
                        break;
                case 2: swap(nums[mid], nums[high--]);
                        break;
            }
        }
    }
};
