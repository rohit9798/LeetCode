Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        set<int> s;
        int i = 0;
        cout<< " " << i;
        if(nums.size() <= 1)
            return false;
        for( i = 0; i <= k && i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        if(i == nums.size())
        {
            if(s.size() < nums.size())
                return true;
        }
        else if(s.size() < k + 1)
            return true;
        for(int i = k + 1; i < nums.size(); i++)
        {
            s.erase(nums[i - k - 1]);
            s.insert(nums[i]);
            if(s.size() < k + 1)
                return true;
        }
        return false;
    }
};
