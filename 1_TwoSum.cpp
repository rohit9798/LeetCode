Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;
        multimap<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m.insert(make_pair(nums[i], i));
        }
        multimap<int, int> :: iterator itr, jtr;
        itr = m.begin();
        jtr = m.end();
        jtr--;
        while(itr != jtr)
        {
            if(itr -> first + jtr -> first < target)
                itr++;
            else if(itr -> first + jtr -> first > target)
                jtr--;
            else if(itr -> first + jtr -> first == target)
            {
                result.push_back(itr -> second);
                result.push_back(jtr -> second);
                break;
            }
        }
        return result;
    }
};
