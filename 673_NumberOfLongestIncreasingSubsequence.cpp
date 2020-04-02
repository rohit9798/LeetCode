Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        if(nums.size() <= 1)
            return nums.size();
        int len[nums.size()];
        int count[nums.size()];
        for(int i = 0; i < nums.size(); i++)
        {
            len[i] = 1; 
            count[i] = 1;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && len[j] + 1 > len[i])
                {
                    count[i] = count[j];
                    len[i] = len[j] + 1;
                }
                else if(nums[i] > nums[j] && len[j] + 1 == len[i])
                    count[i] += count[j];
            }
        }
        int maximum = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(maximum < len[i])
            {
                maximum = len[i];
            }
        }
        int count1 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(maximum == len[i])
                count1 += count[i];
        }
        return count1;
    }
};
