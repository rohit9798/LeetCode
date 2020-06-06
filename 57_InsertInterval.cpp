Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        if(A.size() == 0)
        {
            result.push_back(newInterval);
            return result;
        }
        if(newInterval[1] < A[0][0])
        {
            result.push_back(newInterval);
            for(int i = 0; i < A.size(); i++)
                result.push_back(A[i]);
            return result;
        }
        int i = 0;
        for(i = 0; i < A.size(); i++)
        {
            if(A[i][1] >= newInterval[0])
            {
                break;
            }
            else
            {
                result.push_back(A[i]);
            }
        }
        if(i != A.size())
        {
            vector<int> temp;
            temp.push_back(min(A[i][0], newInterval[0]));
            for(; i < A.size(); i++)
            {
                if(A[i][0] > newInterval[1])
                {
                    temp.push_back(max(A[i - 1][1], newInterval[1]));
                    break;
                }
            }
            if(i == A.size())
                temp.push_back(max(A[i - 1][1], newInterval[1]));
            result.push_back(temp);
            while(i < A.size())
            {
                result.push_back(A[i]);
                i++;
            }
        }
        else
            result.push_back(newInterval);
        return result;
        
    }
};
