Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2




class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         
        map<int, int> m;
        m[0] = 1;
        map<int, int> :: iterator itr = m.begin();
        int result = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(m.find(sum - k) != m.end())
                result += m[sum - k];
            m[sum]++;
        }
        return result; 
    }
};
