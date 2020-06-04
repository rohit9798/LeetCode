Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int first = INT_MAX, second = INT_MAX, count1 = 0, count2 = 0;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(first == nums[i])
                count1++;
            else if(second == nums[i])
                count2++;
            else if(count1 == 0)
            {
                first = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                second = nums[i];
                count2++;
            }
            else
            {
                count2--;
                count1--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(first == nums[i])
                count1++;
            else if(second == nums[i])
                count2++;
        }
        if(count1 > nums.size() / 3)
            result.push_back(first);
        if(count2 > nums.size() / 3)
            result.push_back(second);
        return result;
    }
};
