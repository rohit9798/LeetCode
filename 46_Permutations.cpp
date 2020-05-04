Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


class Solution {
public:
    
    void permutation(vector<int> &nums, vector<int> &count, vector<int> &temp, vector<vector<int>> &result, int level)
    {
        if(level == nums.size())
            result.push_back(temp);
        for(int i = 0; i < nums.size(); i++)
        {
            if(count[i] == 0)
                continue;
            count[i] = 0;
            temp[level] = nums[i];
            permutation(nums, count, temp, result, level + 1);
            count[i] = 1;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> count(nums.size());
        for(int i = 0; i < nums.size(); i++)
            count[i]++;
        int level = 0;
        vector<int> temp(nums.size());
        permutation(nums, count, temp, result, level);
        return result;
    }
};
