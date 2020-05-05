Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]



class Solution {
public:
    
    void combinations(vector<vector<int>> &result, int n, vector<int> &temp, vector<int> &count, int start, int k)
    {
        if(temp.size() == k)
            result.push_back(temp);
        for(int i = start; i < n; i++)
        {
            if(count[i] == 0)
                continue;
            count[i] = 0;
            temp.push_back(i + 1);
            combinations(result, n, temp, count, i + 1, k);
            count[i] = 1;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;
        vector<int> temp;
        vector<int> count(n);
        for(int i = 0; i < n; i++)
            count[i] = 1;
        int start = 0;
        combinations(result, n, temp, count, start, k);
        return result;
        
    }
};
