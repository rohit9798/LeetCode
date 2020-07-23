Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int exor = 0;
        vector<int> result(2, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            exor = exor ^ nums[i];
        }
        int last = exor & -exor;
        for(int i = 0; i < nums.size(); i++)
        {
            if((last & nums[i]) != 0)
                result[0] = result[0] ^ nums[i];
            else
                result[1] = result[1] ^ nums[i];
        }
        return result;
    }
};
