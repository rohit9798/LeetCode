Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]



class Solution {
public:
    
    void combine(vector<vector<int>> &result, vector<int> &nums, vector<int> &count, vector<int> &temp, int start, int sum, int n, int k)
    {
        if(temp.size() == k && sum == n)
            result.push_back(temp);
        for(int i = start; i < 9; i++)
        {
            if(count[i] == 0)
                continue;
            count[i] = 0;
            sum = sum + nums[i];
            temp.push_back(nums[i]);
            combine(result, nums, count, temp, i + 1, sum, n, k);
            count[i] = 1;
            sum = sum - nums[i];
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> temp;
        vector<int> count;
        vector<int> nums;
        for(int i = 0; i < 9; i++)
        {
            nums.push_back(i + 1);
            count.push_back(1);
        }
        int start = 0, sum = 0;
        combine(result, nums, count, temp, start, sum, n, k);
        return result;
    }
};
