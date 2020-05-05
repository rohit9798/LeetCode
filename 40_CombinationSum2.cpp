Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]



class Solution {
public:
    void combine(vector<vector<int>> &result, vector<int> &nums, vector<int> &count, vector<int> &temp, int start, int sum, int target)
    {
        if(sum == target)
            result.push_back(temp);
        else if(sum > target)
            return;
        for(int i = start; i < nums.size(); i++)
        {
            if(count[i] == 0)
                continue;
            count[i]--;
            temp.push_back(nums[i]);
            sum = sum + nums[i];
            combine(result, nums, count, temp, i, sum, target);
            temp.pop_back();
            sum = sum - nums[i];
            count[i]++;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> count;
        map<int, int> m;
        vector<int> nums;
        for(int i = 0; i < candidates.size(); i++)
            m[candidates[i]]++;
        map<int, int> :: iterator itr = m.begin();
        while(itr != m.end())
        {
            nums.push_back(itr -> first);
            count.push_back(itr -> second);
            itr++;
        }
        vector<int> temp;
        combine(result, nums, count, temp, 0, 0, target);
        return result;
    }
};
