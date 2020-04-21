Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.




class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
        map<int, int> m;
        if(nums.size() == 0)
            return 0;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        map<int, int> :: iterator itr = m.begin();
        int start = itr -> first, len = 1, max_len = INT_MIN;
        while(itr != m.end())
        {
            start++;
            if(itr -> first == start)
            {
                len++;
                itr++;
            }
            else
            {
                start = itr -> first;
                itr++;
                if(len > max_len)
                    max_len = len;
                len = 1;
            }
        }
        if(len > max_len)
            max_len = len;
        return max_len;
    }
};
