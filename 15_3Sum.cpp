Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        
        map<vector<int>, int> m;
        int flag = 0;
        vector<vector<int>> result;
        if(A.size() < 3)
            return result;
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size() - 2; i++)
        {
            int j = i + 1;
            int k = A.size() - 1;
            while(j < k)
            {
                if(A[i] + A[j] + A[k] == 0)
                {
                    
                    if(A[i] == 0 && A[j] == 0 && A[k] == 0)
                    {
                        if(flag == 1)
                            break;
                        flag = 1;
                    }
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[k]);
                    if(m.find(temp) == m.end())
                    {
                        m[temp]++;
                        result.push_back(temp);
                    }
                    j++;
                    k--;
                }
                else if(A[i] + A[j] + A[k] < 0)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
};
