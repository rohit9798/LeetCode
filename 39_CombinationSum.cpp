Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]




class Solution {
public:
    void combine(vector<vector<int>> &result, vector<int> &nums, vector<int> &temp, int target, int start, int sum)
    {
        if(sum == target)
            result.push_back(temp);
        else if(sum > target)
            return;
        for(int i = start; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            temp.push_back(nums[i]);
            combine(result, nums, temp, target, i, sum);
            sum = sum - nums[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> temp;
        int start = 0;
        combine(result, candidates, temp, target, start, 0);
        return result;
    }
};
