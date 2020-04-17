Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

 

Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.



class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        map<int, int> m;
        int sum = 0;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]);
            if(k != 0)
                sum = sum % k;
            if(m.find(sum) != m.end())
            {
                if(i - m[sum] > 1)
                    return true;
            }
            else
                m[sum] = i;
        }
        return false;
        
    }
};
