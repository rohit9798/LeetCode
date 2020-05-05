Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]



class Solution {
public:
    void combinations(vector<vector<int>> &result, vector<int> &nums, vector<int> &count, vector<int> &temp, int start)
    {
        result.push_back(temp);
        for(int i = start; i < nums.size(); i++)
        {
            if(count[i] == 0)
                continue;
            count[i] = 0;
            temp.push_back(nums[i]);
            combinations(result, nums, count, temp, i + 1);
            temp.pop_back();
            count[i] = 1;
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> temp;
        vector<int> count(nums.size());
        for(int i = 0; i < count.size(); i++)
            count[i] = 1;
        int start = 0;
        combinations(result, nums, count, temp, start);
        return result;
    }
};
